#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long numb[n],ans=0,sum=0;
	string zifu[n];
	for (int i=0;i<n;i++){
		cin>>numb[i]>>zifu[i];
		sum+=numb[i];
	}
	int star=0,las=n-1;
	while (sum>0){
		if (numb[star]==0){
			star++;
		}
		if (numb[las]==0){
			las--;
		}
		if (star==las){
			break;
		}
		if (numb[star]>=numb[las]){
			numb[star]-=numb[las];
			sum-=2*numb[las];
			if (zifu[star]!=zifu[las]){
				ans+=numb[las];
			}
		}
		else{
			numb[las]-=numb[star];
			sum-=2*numb[star];
			if (zifu[star]!=zifu[las]){
				ans+=numb[star];
			}
		}
	}
	cout<<ans;
	return 0;
}
