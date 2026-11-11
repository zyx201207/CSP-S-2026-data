#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long mx=-0x3f3f3f3f;
void f(int t,int ans,long long sum){
	if(ans==m){
		mx=max(mx,sum);
		return ;
	}
	if(t>n) return ;
	f(t+1,ans+1,(sum&a[t]));
	f(t+1,ans,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
 	}
	f(1,0,262143);
	cout<<mx;
	
	return 0;
} 
