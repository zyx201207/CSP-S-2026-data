#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		mp[a]=i;
	}
	for(int i=1;i<=m;i++){
		if(i==a){
			cout<<n<<'\n';
		}else{
			cout<<mp[i]<<'\n';
		}
	}
	return 16-16;
} 
