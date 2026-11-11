#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+20;
long long n,m,ans=0;
long long a[N];
void dfs(long long step,long long sum){
	if(step>n){
		ans=max(step,ans);
		return;
		}
	dfs(step+1,sum+1);
	dfs(step+1,sum);
	}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long x=0;
	cin>>n>>m;
	bool flag=1;
	bool flag1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]-a[i-1]!=x) flag1=1;
		x=a[i]-a[i-1];
		if(a[i]!=i){
			flag=0;
			break;
		}
	}
	if(flag==1){
		long long m1=m;
		if(m<=n){
			for(int i=m;i>=1;i--){
				if(m1<0) ans--;
				if(m1<1) break;
				if(a[i]<m){
					long long d=m-a[i];
					m1-=d;
					ans++;
					}
			}
			cout<<ans;
			return 0;
			}
		else{
			for(int i=n;i>=1;i--){
				if(m1<0) ans--;
				if(m1<1) break;
				if(a[i]<a[n]){
					long long d=a[n]-a[i];
					m1-=d;
					ans++;
				}
				}
			cout<<ans;
			return 0;
		}
		}
	
	 if(flag1==0){
		 long long m1=m,x1=x;
		 for(int i=1;i<=n;i++){
			 x1*=i;
			 m1-=x1;
			 ans++;
			 if(m1<0){
				 ans--;
				 break;
				 }
			 if(m1==0){ 
				 break;
				 }			 
			 }
			 cout<<ans;
			 return 0;
		 }
	dfs(1,0);
	cout<<ans/2;
	return 0;
}
