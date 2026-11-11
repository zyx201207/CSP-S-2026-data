#include<bits/stdc++.h>
using namespace std;
const long long inf=LLONG_MAX;
int n,m;
long long a[200005],ans;
void f(int ct,int ls,long long cur){
	if(n-ls<m-ct||cur<ans){
		return;
	}
	if(ct==m){
		ans=cur;
		return;
	}
	for(int i=ls+1;i<=n;i++){
		f(ct+1,i,cur&a[i]);
	}
}
bool check(){
	for(int i=1;i<=n;i++){
		bool is=false;
		for(int j=0;j<22;j++){
			if(a[i]==pow(2,j)-1){
				is=true;
				break;
			}
		}
		if(!is){
			return false;
		}
	}
	return true;
}
bool ff(int i1,int i2){
	return i1>i2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
	}else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}else if(check){
		sort(a+1,a+n+1,ff);
		ans=a[m];
	}else{
		f(0,0,inf);
	}
	cout<<ans<<"\n";
	return 0;
}
