#include<bits/stdc++.h>
using namespace std;
int a[1001000],b[1001000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt=1;
	int f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=(i-1)){
			 f=0;
		}
	}
	sort(a+1,a+n+1);
	int q=a[n];
	if(f==1){ 
		cout<<n-m;
		 return 0;
	 }
	if(n==2){
		cout<<(a[1]&a[2]);
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<n;j++){
				b[cnt++]=(a[j]&a[j+1]);
			}
		}
		int maxn=-1;
		for(int i=1;i<=cnt-1;i++){
			maxn=max(maxn,b[i]);
		}
		for(int i=n-1;i>=n-m+1;i--){
			q&=a[i];
		}
		cout<<max(maxn,q);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-m;j++){
			int x=a[j];
			for(int k=(j+1);k<=(j+m);k++){
				x&=a[k];
			}
			b[cnt++]=x;
		}
	}
	int maxn=-1;
	for(int i=1;i<=cnt-1;i++){
		maxn=max(maxn,b[i]);
		//cout<<b[i]<<" ";
	}
	for(int i=n-1;i>=n-m+1;i--){
		q&=a[i];
	}
	cout<<max(maxn,q);
	return 0;
}
