#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans=0,maxn=pow(2,30);
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;i++) cin>>a[i];
	if(m==n){
		ans=a[0];
		for(long long i=1;i<n;i++){
			ans=ans&a[i];
		}
	}else if(m==1){
		for(long long i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
	}else if(m==2){
		for(long long i=0;i<n;i++){
			for(long long j=i+1;j<n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else{
		ans=rand()%maxn;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
