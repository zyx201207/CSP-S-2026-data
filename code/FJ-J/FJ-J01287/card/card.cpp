#include<bits/stdc++.h>
using namespace std;


unordered_map<int,int> mp;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
int n,m;

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		mp[x]++;
	}
	for(int i=1;i<=m;i++){
		if(mp[i]){
			cout<<n<<" ";
		}
		else{
			cout<<0<<" ";
		}
	}
	return 0;
}
