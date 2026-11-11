#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,ws;
	cin>>n>>m;
	long long card[n];
	for(long long i=0;i<n;i++){
		cin>>card[i];
	}
	long long sum[m]={0},lssum[m]={0};
	long long dq[n];
	for(long long i=0;i<n;i++){
		ws=0;
		for(long long j=0;j<n-i;j++)
		dq[ws]=card[i+ws];
		lssum[card[i+ws]-1]++;
		if(lssum[card[i+ws]-1]>1){
			int lsws=ws;
			ws--;
			while(dq[ws]!=dq[lsws]){
				dq[ws]=0;
				ws--;
			}
			dq[lsws]=0;
		}
		for(long long j=0;j<ws;j++){
			sum[dq[j]-1]++;
			dq[j]=0;
		}
	}
	for(long long i=0;i<m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}