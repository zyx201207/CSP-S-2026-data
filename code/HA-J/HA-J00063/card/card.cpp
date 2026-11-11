#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(read,"card.in","r");
	freopen("card.ans","w");
	long long n,m;
	cin>>n>>m;
	long long h[n+10],o[n+10]={},b[m+10]={},l[m+10]={};
	for(long long i=1;i<=n;i++){
		cin>>h[i];
	}
	for(long long k=1;k<=n;k++){
		for(long long i=k;i<=n;i++){
			if(b[h[i]]==0)b[h[i]]++;
			else{
				for(long long j=1;j<=m;j++){
					b[j]=0;
				}
				b[h[i]]++;
			}
		}
		for(long long i=1;i<=m;i++){
			if(b[i]!=0)l[i]++;
			b[i]=0;
		}
	}for(long long i=1;i<=m;i++){
		cout<<l[i]<<" ";
	}
	return 0; 
}
