#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,ans=1;
	int A=1,B=1;
	long long m,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)A=0;
		if(i==2){
			k=a[2]-a[1];
		}
		if(i>2){
			if(k!=a[i]-a[i-1])B=0;
		}
	}
	if(A==1){
		for(int i=1;i<=n;i++){
			if(m-i>=0){
				ans++;
				m-=i;
			}
			else break;
		}
		cout<<ans;
		return 0;
	}
	if(B==1){
		int i=k;
		while(m-i>=0){
			i+=k;
			m-=i;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		a[i]=a[i+1]-a[i];
	}
	sort(a+1,a+n+1);
	int l=0;
	for(int i=1;i<=n;i++){
		l+=a[i];
		if(m-l>=0){
			n-=l;
			ans++;
		}else break;
	}
	cout<<ans;
	return 0;
}
