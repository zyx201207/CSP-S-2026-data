#include<bits/stdc++.h>
using namespace std;
string s1,s2;
char cins; 
long long n,i,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int j=1;j<=n;j++){
		scanf("%lld",&i);
		cin>>cins;
		while(i>0){
			i--;
			s1+=cins;
		}
	}
	for(i=0;i<s1.size();i++){
		s2+=s1[s1.size()-1-i];
	}
	for(i=0;i<=s1.size()/2;i++){
		if(s1[i]!=s2[i]) sum++;
	}
	printf("%lld",sum);
	return 0;
} 

