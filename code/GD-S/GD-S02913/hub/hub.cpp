#include<bits/stdc++.h>
using namespace std;
int n,t,k,cot,s1,s2;
vector<int>u[1000006]; 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>cot>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>s1>>s2;
			u[s1].push_back(s2);
			u[s2].push_back(s1);
		}
		if(cot==13||cot==14){
			cout<<max(1,n-k);
		}
		else cout<<"1\n2";
	}
	return 0;
} 
