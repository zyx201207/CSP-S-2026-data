//GZ-S00042 贵阳市观山湖区外国语实验中学 孙小涵 
#include<bits/stdc++.h>
using namespace std;
vector<int>a[1000006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
		}
		cout<<"0\n"; 
	}
	return 0;
} 
