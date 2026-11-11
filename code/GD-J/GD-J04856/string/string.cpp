#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//BAOLI
	string str;
	int a;
	cin>>a;
	ll ans=0;
	for(int i=1;i<=a;i++){
		int g;
		char h;
		cin>>g>>h;
		string k(g,h);
		str+=k;
	}
	ll len=str.size();
	for(int i=0,j=len-1;i<=j;i++,j--){
		if(str[i]!=str[j])ans++;
	}
	cout<<ans;
	return 0;
}
