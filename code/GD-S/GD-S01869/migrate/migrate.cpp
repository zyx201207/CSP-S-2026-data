#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6+10;

ll c_,t;
ll n,d;
ll a[N],qzh[N];
ll ans;

queue<ll> q[N];

void sch(ll u,ll v){
	int dyd=0;
	
	
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin>>c_>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){cin>>a[i];}
		for(int i=1;i<=n;i++){qzh[i]=qzh[i-1]+a[i];}
		
		if(c_==11||c_==12){
			int dt_x=a[2]-a[1];
			if(d<3*dt_x&&d>=2*dt_x)cout<<n-2<<endl;
		}
		if(c_==13||c_==14){
			int spcl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j)continue;
					int jl=abs(a[j]-a[1]);
					if(abs(a[j]-a[i])!=jl)continue;
					spcl=i;
				}
			}int num=0;
			for(int u=1;u<=n;u++){
				for(int v=1;v<=n;v++){
					if(u==v)continue;
					if(abs(u-v)<=d)num++;
				}
			}cout<<num<<endl;
		}
	}
	
	return 0;
}

