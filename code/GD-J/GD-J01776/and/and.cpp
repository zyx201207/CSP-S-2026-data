#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000000],ma=-1;
void f(long long cnt,long long sum,long long ans){
	if(sum==m){
		if(ans!=-1){
			
			ma=max(ma,ans);
		}
		return;
	}
	if(cnt>n){
		return;
	}
	
	if(sum==0){
		f(cnt+1,sum+1,a[cnt]);
		f(cnt+1,sum,ans);
	}
	else{
		long long e=ans&a[cnt];

		f(cnt+1,sum+1,e);
		f(cnt+1,sum,ans);
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	f(1,0,-1);
	cout<<ma;
	return 0;
}
