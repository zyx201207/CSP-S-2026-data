#include<bits/stdc++.h>
using namespace std;
long long dp[100001];
long long pd[100001]; 
int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m,d,r,cnt=0;	cin>>n>>m;
	
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
while(m){
	cin>>d>>r;
	
	for(int i=1;i<=d;i++){
		cin>>dp[i];
	}for(int j=1;j<d;j++){
		for(int i=1;i<=r;i++){
		pd[j+i]+=1;
	}

	}
	for(int i=3;i<=d;i++){
		if(pd[i]==2){
		cnt++;}
		}cout<<cnt<<endl;cnt=0;m--;}
		return 0;
	}

