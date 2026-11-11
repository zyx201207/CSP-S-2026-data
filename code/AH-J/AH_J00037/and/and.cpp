#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,l[200005],r[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) cnt++;
	}
	l[1]=a[1];
	r[n]=a[n];
	if(cnt>n-m){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int an=a[1];
		for(int i=2;i<=n;i++) an&=a[i];
		cout<<an;
		return 0;
	}
	if(m==2){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1){
		int x=a[2];
		for(int i=3;i<=n;i++) x&=a[i];
		if(cnt==1){
			cout<<x;
			return 0;
		}
		int maxn=x;
		for(int i=2;i<=n;i++){
			l[i]=l[i-1]&a[i];
		}
		for(int i=n-1;i>=1;i--){
			r[i]=r[i+1]&a[i];
		}
		for(int i=2;i<=n;i++){
			maxn=max(maxn,l[i-1]&r[i+1]);
		}
		cout<<maxn;
		return 0;
	}
	cout<<a[m];
	return 0;
}
