#include<bits/stdc++.h>
using namespace std;
string s="";
void f(long long i,string z){
	for(int j=1;j<=i;j++)s+=z;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int j;
		string sp;
		cin>>j>>sp;
		for(int f=j;j>=1;j--)s+=sp;
	}
	cout<<s;
	long long m=s.size();
	long long ans=0;
	for(int i=0;i<m/2;i++){
		if(s[i]!=s[m-i+1])ans++;
	}
	cout<<ans;
	return 0;
}
