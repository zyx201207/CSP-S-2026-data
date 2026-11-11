#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=2e6+5;
ll c,t,n,d,x[inf];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int cha=0,can1=1;
		int p,can2=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>2){
				if(cha!=x[i]-x[i-1]) can1=0;
			}
			if(i>1) cha=x[i]-x[i-1];
		}
		for(int i=1;i<=n;i++){
			if(x[i]-x[1]<=d&&x[n]-x[1]<=d){
				p=i;
				can2=1;
			} 
		}
		if(n<=3) cout<<0<<'\n';
		else if(can1){
			int sum=d/cha;
			if(sum!=2) cout<<0<<'\n';
			else cout<<(n-3);
		}
		else if(can2){
			cout<<0<<'\n';
		}
		else{
			int sum=0,ans=0;
			for(int i=1,j=1;i<=(x[n]-x[1])/d+1;i++){
				while((x[j]-x[1])<i*d){
					sum++;
					j++;
				}
				if(sum==2){
					ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
