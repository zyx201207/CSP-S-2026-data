#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+16;
int c,t,n,d,a[N],nex[N];
int dis(int x,int y){
	return labs(a[y]-a[x]);
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate1.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(;t;t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			nex[i]=i;
		}
		int l=1,r=1;
		a[n+1]=2e19;
		while(l<=r){
			while(dis(l,r+1)<=d and r<=n)r++;
			nex[l]=r,l++;
		}
//		for(int i=1;i<=n;i++)cout<<nex[i]<<" ";
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=-1,y=-1,z=i,t=0;
				while(t<2){
					x=y,y=z,z=min(j,nex[z]);
//					if(i==1 and j==4)cout<<x<<" "<<y<<" "<<z<<endl;
					if(y==z)break;
					if(x==-1)continue;
					if(y+1!=z and dis(x,y)+dis(y,y+1)<=d)t++;
					if(y-1!=x and dis(y,z)+dis(y-1,y)<=d)t++;
					if(y-2!=x and dis(y,z)+dis(y-2,y)<=d)t++;
					if(y+2!=z and dis(x,y)+dis(y,y+2)<=d)t++;
					if(nex[z]>j)break;
				}
//				if(i==1 and j==4)cout<<t<<endl; 
				if(t==1 and z>=j){
					ans++;
//					cout<<i<<" "<<j<<endl;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*

*/
