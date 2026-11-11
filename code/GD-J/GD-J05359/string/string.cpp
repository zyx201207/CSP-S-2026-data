#include<bits/stdc++.h>
using namespace std;
long long n,g[27];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long x;
		char a;
		cin>>x>>a;
		g[a-96]+=x;
		for(int i=1;i<=x;i++)s=s+a;
	}
	sort(g+1,g+26,cmp);
	if(g[2]==0){
		cout<<0;
	}else{
		cout<<g[1];
	}
	return 0;
}
