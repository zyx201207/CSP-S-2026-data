#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
long long sum,n,m,cnt;
char sa,s[100000000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>sa;
		for(int i=sum;i<=sum+m;i++){
			s[i]=sa;
		}
		sum+=m;	
	}
	for(int i=0;i<sum/2;i++){
		if(s[i]!=s[sum-i-1])cnt++;
	}
	cout<<cnt;
	return 0;
} 
