#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
long long ai[514514],aj[514514];
char bi[514514],bj[514514];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ai[i]>>bi[i];
		aj[n-i+1]=ai[i];
		bj[n-i+1]=bi[i];
	}for(int i=2;i<=n;i++){
		ai[i]+=ai[i-1];
		aj[i]+=aj[i-1];
	}ai[n+1]=ai[n];
	aj[n+1]=aj[n];
	long long ti=1,tj=1,ed=0;
	while(ti<=n && tj<=n){
		if(ai[ti]<aj[tj]){
			if(bi[ti]!=bj[tj]){
				sum+=ai[ti]-ed;
			}ed=ai[ti];
			ti++;
		}else if(ai[ti]>aj[tj]){
			if(bi[ti]!=bj[tj]){
				sum+=aj[tj]-ed;
			}ed=aj[tj];
			tj++;
		}else{
			if(bi[ti]!=bj[tj]){
				sum+=ai[ti]-ed;
			}ed=ai[ti];
			ti++;
			tj++;
		}
	}cout<<sum/2;
	return 0;
} 
