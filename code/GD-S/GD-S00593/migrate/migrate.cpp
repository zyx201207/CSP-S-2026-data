#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max(a,b) a>b?a:b
#define min(a,b) a>b?b:a  
const int N=2e6+10;
int n;
int t;
ll d,x[N],ans;
int L[N],R[N],f[N],g[N];
bool chk(int x,int y){
	return L[x]==L[y]&&R[x]==R[y];
} 
void sol(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n+1;i++){
		f[i]=g[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int r=1,l=1;l<=n;l++){
		while(x[r+1]-x[l]<=d&&r+1<=n){
			r++;
		}
		R[l]=r;
	}
	for(int r=n,l=n;l>=1;l--){ 
		while(x[l]-x[l-1]<=d&&l-1>=1){
			--l;
		}
		L[l]=l;
	}
	for(int i=1;i<n;i++){
		f[i]++;
		f[R[i]]+=f[i];
	}
	f[n]++;
	for(int i=n;i>1;i--){
		g[i]++;
		g[L[i]]+=g[i];
	}
	g[1]++; 
	
	for(int i=2;i<n-1;i++){
		if(chk(i,i+1)&&(!chk(i,i-1))&&(!chk(i+1,i+2))){
			int x=L[i],y=R[i];
			int cntx=0,cnty=0;
			cntx=f[x]+(x-L[x]),cnty=g[y]+(R[y]-y);
			
			ans=1LL* cntx*cnty+1LL*cntx*(R[i]-i-2)+1LL*cnty*(i-L[i]-1);
		}else if(R[i-1]==i+1&&L[i+2]==i){
			ans++;
		} 
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c;
	cin>>c>>t;
	while(t--){
		sol();
	} 
	
	return 0;
}


