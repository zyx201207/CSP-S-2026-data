#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+10,INF=0x3f3f3f3f;
int c,t,n,d,x[N],f[N],ans;
void qmain(){
	cin>>n>>d;
	if(d==2e18){
		cout<<n<<endl;
		return ;
	}
	memset(f,INF,sizeof f);
	for(int i=1;i<=n;i++)
		cin>>x[i];
	f[0]=0,ans=0;
	for(int i=1;i<=n;i++){
		int j=i;
		while(1){
			j--;
			if(x[i]-x[j]>d||j==-1)
				break;
			f[i]=min(f[i],f[j]+1);
		}
		int num=0;
		j=i;
		while(1){
			j--;
			if(x[i]-x[j]>d||j==-1)
				break;
			if(f[j]+1==f[i])
				num++;
		}
		if(num==2)
			ans++;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		qmain();
	}
	return 0;
}
