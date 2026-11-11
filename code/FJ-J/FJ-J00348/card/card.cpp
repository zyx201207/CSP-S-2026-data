#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n]={},num[m]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	memset(num,0,m);
	for(int i=0;i<n;i++){
		vector<int> card(0);
		for(int j=i;j<n;j++){
			if(find(card.begin(),card.end(),a[j])!=card.end()){
				card.erase(find(card.begin(),card.end(),a[j]),card.end());
				
				card.push_back(a[j]);
			}else{
				card.push_back(a[j]);
			}
		}
		for(int x:card){
			num[x-1]++;
		}
	}
	for(int i=0;i<m;i++){
		if(num[i]){
			cout<<num[i]<<" ";
		}
	}
	return 0;
}
