#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
using namespace std;
#define int1 long long
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int1 n;
	int1 cnt=0;
	cin>>n;
	string ss="0";
	for(int1 i=1;i<=n;++i){
		int1 num;char c;
		cin>>num>>c;
		for(int i=1;i<=num;++i)
		ss+=c;
	}
	for(int1 i=1;i<=((int)ss.size())/2;++i)
	if(ss[i]!=ss[(int)ss.size()-i])
	++cnt;
	cout<<cnt;
}
