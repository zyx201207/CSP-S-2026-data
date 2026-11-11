#include<bits/stdc++.h>
using namespace std;
long long n,m[10005];
int q;
long long ans=0,cnt=0;
long long qw(long long a[],long long n,long long q){
	if(q==0)return ans;
	for(long long i=0;i<n;i++){
		ans=max(ans&qw(a,n,q-1),a[i]&ans);
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>m[i];
	}if(q==1){
		for(int i=0;i<n;i++){
			ans=max(ans,m[i]);
		}
	}else if(q==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			if(i==j)continue;
			ans=max(ans,m[i]&m[j]);
			}
		}
	}else{
		qw(m,n,q);
	}
	cout<<ans;
	return 0;
}//Trick||Treat!
