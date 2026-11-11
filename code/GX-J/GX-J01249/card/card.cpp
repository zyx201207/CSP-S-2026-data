#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,s,d[100009]={0};
	cin>>a>>s;
	for(int i=1;i<=a;i++){
		cin>>d[i];
		}
		for(int i=1;i<=a;i++){
		if(d[i]!=0){
			d[i]=(d[i]+d[i+1]-d[i-2]+d[i+3])%(s+3);
		}
		}
		for(int i=1;i<=a;i++){
		if(d[i]>0){
			cout<<d[i]<<' ';
		}
		}
	return 0;
	}
