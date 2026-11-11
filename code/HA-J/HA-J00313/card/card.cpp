#include<bits/stdc++.h>
using namespace std;
#define ll long long
int car[500005],maxn=INT_MIN;
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string desk="";
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>car[i];
		maxn=max(car[i],maxn);
	}
	for(int ju=1;ju<=n;ju++){
		desk="";
		for(int i=ju;i<=n;i++){
			if(desk.find(to_string(car[i]))!=string::npos){
				desk.erase(desk.find(to_string(car[i])));
				desk+=to_string(car[i]);
				desk+=",";
			}else{
				desk+=to_string(car[i]);
				desk+=",";
			}
		}
		for(int i=1;i<=maxn;i++){
			if(desk.find(to_string(i))!=string::npos){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=maxn;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
