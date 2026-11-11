#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	long long ans=0;
	cin>>n;
	long long amount[n];
	char dir[n];
	for(int i=0; i<n; i++){
		cin>>amount[i]>>dir[i];
	}
	int i=0, j=n-1;
	while(amount[i]!=0 && amount[j]!=0){
		if(dir[i]==dir[j]){
			if(amount[i]>=amount[j]) amount[i]-=amount[j]; amount[j]=0; j--;
			if(amount[j]>=amount[i]) amount[j]-=amount[i]; amount[i]=0; i++;
		}else{
			if(amount[i]>=amount[j]) amount[i]-=amount[j]; ans+=amount[j]; amount[j]=0; j--;
			if(amount[j]>=amount[i]) amount[j]-=amount[i]; ans+=amount[i]; amount[i]=0; i++;
		}
	}
	printf("%lld",ans);
}
