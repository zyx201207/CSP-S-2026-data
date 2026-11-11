#include<bits/stdc++.h>
using namespace std;
int jishu[30]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0;
	int n,f_mx=0;
	cin>>n;
	for(int i=1;i<=n;i++){//a=97
	int a,c;
	char b;
	cin>>a>>b;
	c=b;
	c-=97;
	jishu[c]+=a;
	sum+=a;
	}
	for(int i=0;i<26;i++){
	f_mx=max(f_mx,jishu[i]);}
	cout<<sum-f_mx;
	return 0;
}

