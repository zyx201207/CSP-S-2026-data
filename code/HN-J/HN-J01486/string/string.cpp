#include<bits/stdc++.h>
using namespace std;
long long n,sum,k,l;
char s1[10000000];
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		char b;
		cin>>a>>b;
		l+=a;
        for(int j=k;j<=k+a-1;j++){
        	s1[j]=b;
		}
		k+=a;
	}
	for(int i=0;i<=l/2;i++){
		if(s1[i]!=s1[l-1-i]){
			sum++;
			s1[l-1-i]=s1[i];
		}
	}
	cout<<sum;
	return 0;
}
