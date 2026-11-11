#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,zd,z,y,t[600000],l[1000],k,cnt=0,sum=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>t[i];
	while(n--){
		cin>>k;
		for(int i=1;i<=2*k;i++){
			cin>>l[i];
		}
	}
	while(q--){
		cin>>z>>y;
	}
	while(q--){
		for(int i=1;i<=2*k;i+=2){
			cnt+=l[i+1];
			
		}
	}
	for(int i=1;i<=m;i++)cnt+=t[i];
	cout<<cnt;
}

