#include<bits/stdc++.h>
using namespace std;
string s;
int n,ac=0,s=0;
int a[200005],zm[25];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    if(n<=1){
    	cout<<0;
    	return 0;
	}
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
    	zm[c[i]-97]++;//每个字母的个数 
	}
	if(n=2){
		if(a[1]<=a[2]){
			cout<<a[i];
		}
		else if(a[1]>a[2]){
			cout<<a[2];
		}
		return 0;
	}
	for(int i=0;i<=25;i++){
		if(zm[i]>=1){
			s++;//含有的字母个数 
		}
	}
	for(int i=1;i<=n;i++){
		ac+=a[i];//字符串的总长度 
	}
	char zb[ac];
	int bg=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			zb[bg]=c[i]; 
			bg++;
		}
	}
	int jjj,ccc=0;
	for(int i=1;i<=ac;i++){
		jjj=0;
		while(zb[i]!=zb[zc+1-i]){
			zb[i]++;
			jjj++;
		}
		if(jjj=!1){
			ccc++;
		}
	}
	cout<<ccc;
	return 0;
} 
