#include<bits/stdc++.h>
using namespace std;
int main(){
	string mmm;
	long long n,ch=0,ss=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long m;
		cin>>m;
		char c;
		cin>>c;
		for(int j=1;j<=m;j++){
			ss++;
			mmm[ss]=c;
		}
	}
	if(ss%2==0){
		ss/=2;
		for(int i=ss;i>=1;i--){
			ch++;
			if(mmm[i]!=mmm[ss+ch]){
				sum++;
			}
		}
	}
	if(ss%2==1){
		ss=(ss-1)/2+1;
		ch=-1;
		for(int i=ss;i>=1;i--){
			ch++;
			if(mmm[i]!=mmm[ss+ch]){
				sum++;
			}
		}
	} 
	cout<<sum;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	return 0;
} 
