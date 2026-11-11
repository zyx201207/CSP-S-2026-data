#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int ans;
long long sum;

void Init(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		string str;
		cin>>a;
		sum+=a;
		cin>>str;
		for(int j=0;j<a;j++){
			s+=str;
		}
	}
}

void solve(){
	for(int i=0;i<sum/2;i++){
		if(s[i]!=s[sum-i]){
			ans++;
		}
	}
}

void Printf(){
	cout<<ans;
}

int main(){
	Init();
	solve();
	Printf();
	return 0;
}
//¼ÇµÃÉ¾×¢ÊÍ 
/*
3
2 a
2 b
1 c
*/
