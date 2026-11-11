#include <iostream>
#include <cstring>
using namespace std;
long long n,ai[200000],k=0,ans=0;
char ci[200000];
string S;
int main(){
	freopen("sting.in","r",stdin);
	freopen("sting.out","w",stdout);
	cin>>n;
	int z=0;
	for(long long i=0;i<n;i++){
		cin>>ai[i]>>ci[i];
		k+=ai[i];
		for(long long j=0;j<ai[i];j++){
			S[z]=ci[i];
			z++;
		}
	}
	k--;
	if(k%2==0){
		k=k/2;
		for(long long i=1;i<=k;i++){
			if(S[k+i]!=S[k-i]) ans++; 
		}
	}else{
		k=k/2;
		for(long long i=1;i<=k;i++){
			if(S[k+i]!=S[k-i+1]) ans++; 
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000 a
1000 a
1000 a
1000 b
1000 b
1000 b

*/
