#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510;
ll c,n,m,d,q,w[N],k,sum;
struct Node{
	ll t1[N];
}t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>t[i].t1[j];
		}
	} 
	ll st,ed;
	while(cin>>st>>ed){
		sum=0;
		sum=sum+w[st]+w[ed];
		for(int i=1;i<=2*k;i++){
			for(int j=2*k;j>=1;j--){
				if(i==st&&j==ed)sum+=t[i].t1[j];
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
