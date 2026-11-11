#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	/*-----*/
	long long n,m;
	cin>>n>>m;
	long long card[n+1];
	for(long long i=1;i<=n;i++){
		cin>>card[i];
	}
	for(long long i=1;i<=m;i++){
		long long r=0;
		for(long long j=1;;j++){
			if(card[j]>i)break;
			r++;
		}
		cout<<r<<' ';
	}
	return 0;
	/*-----*/
	fclose(stdin);
	fclose(stdout);	
} 
