#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	pair<int,char>b[a];
	for(int i=0;i<a;i++){
		cin>>b[i].first>>b[i].second;
	}string ans="";
	for(int i=0;i<a;i++){
		for(int j=0;j<b[i].first;j++){
			ans+=b[i].second;
		}
	}int cnt=0;
	for(int i=0;i<ans.length()/2;i++){
		if(ans[i]!=ans[ans.length()-i-1])cnt++;
	}cout<<cnt;
	return 0;
}
