#include<bits/stdc++.h>
using namespace std;

char d[1000000000],e[1000000000];
int main(){
	freopen("string.in","r",stdin);
	//freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long b;
	char c;
	long long s=1,t=1;
	long long k=0;
	for(long long i=1;i<=n;i++){
		cin>>b>>c;
		for(long long j=1;j<=b;j++){
			d[s]=c;
			s++;
		}
	}
	for(long long i=s;i>=1;i--){
		e[t]=d[i];
		t++;
	}
	for(long long i=1;i<=s;i++){
		if(d[i]==e[i]){
			continue;
		}else if(d[i]!=e[i]){
			d[s+1-i]=e[i];
			e[s+1-i]=e[i];
			k++;
		}
	}
	cout<<k;
	return 0;
}
		
