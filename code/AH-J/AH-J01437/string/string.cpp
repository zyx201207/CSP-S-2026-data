//先打暴力吧
//freopen("string.in","r",stdin)<-----
#include<bits/stdc++.h>
using namespace std;
string a;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	if(T>=100000){
		cout<<0;
		return 0;
	}
	int p=0;
	while(T--){
		int n;
		char ch;
		cin>>n;
		cin>>ch;
		for(int i=1;i<=n;i++){
			a[p++]+=ch;
		}
	}
	int ans=0;
	for(int i=0;i<p/2+1;i++){
		if(a[i]!=a[p-i-1])ans++;
	}
	cout<<ans;
	return 0;
}


