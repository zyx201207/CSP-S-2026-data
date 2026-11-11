#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card1.in","r",stdin);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,c,e=0;
	cin>>a>>c;
	long long b[a],d[c];
	for(long long i=1;i<=c;i++){d[i]=0;}
	for(long long i=1;i<=a;i++){cin>>b[i];}
	for(long long i=a;i>=1;i--){
		d[b[a]]++;
		for(long long j=a;j>=i;j--){
			e=0;
			for(long long k=1;k<j;k++){if(b[k]==b[j]){e++;}}
		}
		if(e%2==0){
			if(b[a]==1){d[2]++;}
			else{d[1]++;}
		}
	}
	if(d[1]>d[2]){d[2]-=1;}
	else{d[1]-=1;}
	cout<<d[1]<<" "<<d[2];
	return 0;
}
