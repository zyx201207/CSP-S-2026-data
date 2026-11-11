#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+5;
const ll inf=1e18;
ll c,t,num=1;
struct abc{
	int u,v;
}a[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k,num;
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			cin>>a[i].u>>a[i].v;
		}
		cout<<num++;
	}
	return 0;
}
