#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
ll n,d;
ll a[2000010];
ll last[2000010],last2[2000010];
ll z[2][2000010],o[2][2000010];
ll dpa[2000010];
ll op[2000010];
ll op2[2000010];
struct node{
	ll id,x;
};
queue<node>sta;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		cin>>a[i],z[0][i]=0,z[1][i]=0,o[0][i]=0,o[1][i]=0,dpa[i]=0,op[i]=0,op2[i]=0;
		while(sta.size())sta.pop();
		sta.push({1,a[1]+d});
		for(ll i=2;i<=n;i++){
			if(sta.front().x>a[i]){
				sta.push({i,a[i]+d});
				continue;
			}else{
				while(sta.size()&&a[i]>=sta.front().x)
				last[sta.front().id]=(a[i]==sta.front().x?i:i-1),sta.pop();
				sta.push({i,a[i]+d});
			}
		}
		for(ll i=1;i<=n;i++)
			if(last[i]==0)last[i]=n+1;
		//cout<<"done"<<endl;
		while(sta.size())sta.pop();
		sta.push({n,a[n]-d});
		for(ll i=n-1;i>=1;i--){
			if(sta.front().x<a[i]){
				sta.push({i,a[i]-d});
				continue;
			}else{
				while(sta.size()&&a[i]<=sta.front().x)
				last2[sta.front().id]=(a[i]==sta.front().x?i:i+1),sta.pop();
				sta.push({i,a[i]-d});
			}
		}
		//cout<<"done"<<endl;
		for(ll i=1;i<=n;i++){
			//cout<<i<<":"<<last[i]<<" "<<last2[i]<<endl;
			if(i==last2[last[i]])
			z[0][i]=1,z[1][last[i]]=1;
			//cout<<z[0][i]<<","<<z[1][i]<<endl;
		}
		//cout<<"=="<<ans<<endl;
		for(ll i=n;i>=1;i--){
			
			if(z[0][i]){
				op[i]=op[last[i]]+1;
				dpa[i]+=dpa[last[i]];
				ans+=dpa[i];
				//cout<<i<<":->>"<<dpa[i]<<","<<op[i]<<endl;
			}
			if(z[1][i]){
				if(last[i-2]<=n&&last[i-1]<=n)
				dpa[i]=last[i-1]-last[i-2]+(last[i-2]+1==i?-1:0);
				else if(last[i-2]>n)
				dpa[i]=0;
				else dpa[i]=n-last[i-2]+(last[i-2]+1==i?-1:0);
			}
			//cout<<i<<":->>"<<dpa[i]<<","<<op[i]<<endl;
		}
		//cout<<"=="<<ans<<endl;
		for(ll i=1;i<=n;i++){
			if(last2[last[i]]==i-1&&i!=1)
			o[0][i]=1,o[1][last[i]]=1;
			if(z[1][i])
			op2[i]=op2[last2[i]]+1;
		}
		for(ll i=1;i<=n;i++){
			if(o[0][i]){
				if(op[last[i]]>0)
				ans+=(op2[i]+1)*op[last[i]];
			}
		}
		cout<<ans<<endl;
	}
			
    return 0;
}
