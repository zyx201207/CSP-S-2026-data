#include<bits/stdc++.h>
using namespace std;
const int N=100000005;
int n,m,ans,a,b[N],c[N],d;
void er(int n){
	for(int i=1;i<=N;i++){
		if(n%2==1) b[i]=1;
		else b[i]=0;
	}
	for(int i=N;i>=0;i--){
		c[i]=b[i];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;	
	}
	ans=1^a;
	cout<<ans<<endl;
	return 0;
}
