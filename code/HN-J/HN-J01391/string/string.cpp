#include<bits/stdc++.h>
using namespace std;//Trick||Treat! travel
long long n;
char a[10000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char card;
	long long shu=1,o;
	for(long long i=1;i<=n;i++){
		cin>>o>>card;
		for(long long j=1;j<=o;j++){
			a[shu]=card;
			shu++;
		}
	}
	shu-=1;
	long long s=0;
	if(shu%2==0){
		for(long long i=1;i<=shu/2;i++){
			if(a[i]!=a[shu-i+1]){
				s++;
			}
		}
	}
	if(shu%2!=0){
		for(long long i=1;i<=shu/2+1;i++){
			if(a[i]!=a[shu-i+1]){
				s++;
			}
		}
	}
	cout<<s;
	return 0;
} 
