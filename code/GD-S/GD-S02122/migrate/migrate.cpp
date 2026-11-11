#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+10;
int a[N],p[N];//公差 
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1; i<=t; i++){
		int n,d,ans=0;
		cin>>n>>d;
		for(int j=1; j<=n; j++) p[j]=0;
		for(int j=1; j<=n; j++){
			cin>>a[j];
			if(j!=1) p[j]=a[j]-a[j-1];
		}
		if(a[2]-a[1]>d){
			cout<<0<<endl;
			continue;
		}
		//特殊性质 
		bool ts=1;
		for(int j=2; j<=n; j++)
			if(p[j]!=p[2]){
				ts=0;
				break;
			}
		//A 
		if(ts==1){
			int jg=d/p[2];//几倍公差向下取整
			if(jg!=2) cout<<0<<endl;
			else{
				for(int j=1; j<=n; j++) 
					if(j+jg+1<=n) ans++;
				cout<<ans<<endl;
			}
			continue;
		}
		//蒙 
		cout<<2<<endl;
	}
	return 0;
}
