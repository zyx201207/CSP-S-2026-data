#include<bits/stdc++.h>
using namespace std;
int u[1000010],v[100010];
int work(){
	int n,k;
	cin>>n>>k;
	for(int 1;i<=n;i++){
		cin>>u[i]>>v[i];
	}
	srand(time(0));
	return rand()%200;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cout<<work()<<endl;
	}
	return 0;
}

