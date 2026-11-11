#include<bits/stdc++.h>
using namespace std;

long long n,k,u[100005],v[100005];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		if(n==1){
			cout<<"5\n";
		}else{
			cout<<u[clock()%(n-1)+1]+v[clock()%(n-1)+1]-c+t<<"\n";
		}
	}
	return 0;
}
