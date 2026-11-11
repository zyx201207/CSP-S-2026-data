#include<bits/stdc++.h>
using namespace std;

int main(){
//freopen("string.in","r",stdin);
//freopen("string.out","w",stdout);
	int r;
	cin>>r;
	int ans=0;
	int nsum=0;
	long n[r+1];
	char s[r+1];
	for(int i=1;i<=r;i++){
		cin>>n[i]>>s[i];
		nsum+=n[i];
		}
	long insL;
	long insR;
	insL=nsum/2;
	if(nsum%2==0){
		insR=nsum/2+1;
	}
	if(nsum%2!=0){
		insR=nsum/2+1;
		insL=nsum/2+1;
	}
	int nsum1=0;
	int nsum2=nsum;
	int i1=1;
	int i2=r;
	while(insL>nsum1+n[i1]){
		nsum1+=n[i1];

	}
	i1--;
	while(insR<nsum2-n[i2]){
		nsum2-=n[i2];
		i2--;
	}


	while(insL>=0){

		if(s[i1]!=s[i2]){
			ans+=min(insL-nsum1,nsum2-insR);
		}
		insL-=min(insL-nsum1,nsum2-insR);
		insR+=min(insL-nsum1,nsum2-insR);

		if(insL-nsum1>nsum2-insR){
			i2++;
			nsum2+=n[i2];
		}
		else if(insL-nsum1>nsum2-insR){
			i1--;
			nsum1-=n[i1];
		}
		else{
			i2++;
			i1--;
			nsum2+=n[i2];
			nsum1-=n[i1];
		}
	}

	cout<<ans;

}
