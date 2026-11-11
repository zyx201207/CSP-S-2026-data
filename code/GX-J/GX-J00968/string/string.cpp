#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
#define LL long long
using namespace std;
const int N=100001;
LL n,len,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++)	s+=c;
		len+=x;
	}
	for(int i=0,j=len-1;i<j;i++,j--){
		if(s[i]!=s[j])	ans++;
	}
	cout<<ans;
	return 0;
}

