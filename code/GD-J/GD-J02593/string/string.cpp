#include<bits/stdc++.h>
using namespace std;
string snn;
long long nn1,anss=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>nn1;
	for(long long i=1;i<=nn1;i++){
		char cnn;
		long long ann;
		cin>>ann>>cnn;
		for(long long j=1;j<=ann;j++){
			snn+=cnn;
		}
	}
	for(long long i=1;i<=snn.size();i++){
		if(snn[i]!=snn[snn.size()+1-i]){
			snn[snn.size()+1-i]=snn[i];
			anss++;
		}
	}
	if(nn1==1){
		cout<<0;
		return 0;
	}
	cout<<anss;
	return 0;
}
