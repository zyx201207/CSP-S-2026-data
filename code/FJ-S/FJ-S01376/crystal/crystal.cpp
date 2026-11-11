#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long sum[n],cha=1;
	for (int i=0;i<n;i++){
		cin>>sum[i];
	}
	sort(sum,sum+n+1);
	long long sumch[n-1];
	bool boool=1;
	for (int i=0;i<n-1;i++){
		sumch[i]=sum[i+1]-sum[i];
		if (i>0){
			if (sumch[i]!=sumch[i-1]){
				boool=0;
			}
		}
	}
	if (boool==1){
		int maxn=0;
		int maxnn=1;
		for (int i=1;i<n;i++){
			maxn+=sumch[0]*i;
			if (maxn<=m){
				maxnn=i+1;
			}
			else{
				break;
			}
		}
		cout<<maxnn;
	}
	else{
		for (int i=0;i<n-1;i++){
			int sfs=1;
			for (int j=i;j<n-1;j++){
				if (sfs==1){
					int smallcha=0,js=0;
					for (int x=j;x>=i;x--){
						js+=sumch[x];
						smallcha+=js;
						if (smallcha>m){
							sfs=0;
							break;
						}
						else if(j-x+2>cha){
							cha=j-x+2;
						}
					}
				}
			}
		}
		cout<<cha;
	}
	return 0;
}
