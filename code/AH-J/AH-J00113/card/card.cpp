#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
char a[500005];
map<char,ll>ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		string card;
		card+=a[i];
		for(int j=i+1;j<=n;j++){
			int s=card.find(a[j],0);
			if(card.find(a[j],0)==string::npos){
				card+=a[j];
			}
			else{
				card.erase(s,j-s-1);
				card+=a[j];
			}
		}
		int len=card.size();
		for(int j=0;j<len;j++){
			ans[card[j]]++;
		}
	}
	for(auto e:ans){
		cout<<e.second<<" ";
	}
	return 0;
}
