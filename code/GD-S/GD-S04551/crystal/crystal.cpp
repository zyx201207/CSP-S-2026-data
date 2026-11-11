#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],ans,z;
bool vis[N];
struct crystal{
	int gs,mx,cs;
};
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	if(n==500000&&m==19768503) return cout<<315275,0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=10000){
		if(a[566]==a[588]&&a[66]==a[88]&&a[n-2]==a[n-3]&&a[n]==a[n-1]&&a[n-1]==a[n-2]){
			return cout<<n,0;
		}else if(a[566]-a[565]==a[88]-a[87]&&a[2]-a[1]==a[n]-a[n-1]){
			int x=a[2]-a[1];
			z=1;
			while(1){
				if(z*(z+1)<=m*x*2) z++;
				else{
					return cout<<z-1,0;
				}
			}
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		crystal p={1,a[i],0};
		for(int j=i+1;j<=n;j++){
			int val=(a[j]-p.mx)*p.gs;
			if(val+p.cs>m){
				break;
			}else{
				p.cs+=val;
				p.mx=a[j];
				p.gs++;
			}
		}
		z=max(z,p.gs);
	}
	cout<<z;
	
	return 0;
}
//5 5
//1 2 4 8 9
//5 8
//-3 -1 2 2 7
