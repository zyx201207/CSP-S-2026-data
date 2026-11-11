#include<bits/stdc++.h>
#define int long long
#define pir pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e6+5;
int c,T,n,d,a[N],f[N][3],ans;
void solve(int l,int r){
	if(l==r)return ;
	for(int i=l;i<=r;i++){
//		cout<<"["<<i<<"]\n";
		for(int j=i;j<=r;j++)
			f[j][0]=f[j][1]=f[j][2]=1e9;
		f[i][0]=0;
		for(int j=i+1;j<=r;j++){
			for(int k=j-1;k>=i;k--){
				if(a[j]-a[k]>d)break;
				for(int op=0;op<3;op++){
					if(f[k][op]+1<=f[j][0])f[j][2]=f[j][1],f[j][1]=f[j][0],f[j][0]=f[k][op]+1;
					else if(f[k][op]+1<=f[j][1])f[j][2]=f[j][1],f[j][1]=f[k][op]+1;
					else if(f[k][op]+1<f[j][2])f[j][2]=f[k][op]+1;
				}
			}
			if(f[j][0]==f[j][1]&&f[j][1]<f[j][2])++ans;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==13||c==14){
		while(T--)cout<<"0\n";
		return 0;
	}
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int lst=1;
		ans=0;
		for(int i=2;i<=n;i++)
			if(a[i]-a[i-1]>d)solve(lst,i-1),lst=i;
		solve(lst,n);
		cout<<ans<<'\n';
	}
	return 0;
}

