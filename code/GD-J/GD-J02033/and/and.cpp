#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=2e5+5;
ll n,m,ans,G[N],C[31];
bool f[N][31];
struct S{
	ll a;
	ll G;
	ll id;
}A[N];
bool c(S a1,S b){
	if(a1.G==b.G) return a1.a>b.a;
	return a1.G>b.G;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ans=(1<<30)-1;
	//cout<<ans;
	ll at,j;
	for(int i=1;i<=n;i++){
		cin>>at;
		j=0;
		A[i].a=at;
		A[i].id=i;
		while(at!=0){
			f[i][j]=at%2;
			at/=2;
			j++;
			if(f[i][j-1]==1){
				C[j-1]++;
			}
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			A[i].G+=f[i][j]*C[j];
		}
	} 
	sort(A+1,A+n+1,c);
	for(int i=1;i<=m;i++){
		ans&=A[i].a;
		//cout<<A[i].a<<" "<<ans<<endl;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
