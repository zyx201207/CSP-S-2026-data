#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long d[100000]={};
	int a,l=0,k=0;
	cin>>a;
	char s[100000]={};
	for(long long i=1;i<=a;i++){
		cin>>d[i]>>s[i];
	}
	string x;
	long long g,h;
	for(long long i=1;i<=a;i++)h+=d[i];
	for(long long i=1;i<=a;i++){
		for(long long j=1;j<=d[i];j++)x[i]=s[i];
	}
	for(long long i=1;i<=a;i++){
		if(d[1]!=d[i]){
			break;
		}
		l++;
	}
	for(long long i=1;i<=l;i++)g+=d[i];
	for(h;h>=g;h--){
		if(x[h]!=d[1]){
			k++;
		}
	}
	cout<<k;
	return 0;
} 
