#include<bits/stdc++.h>
using namespace std;
string s;
char a;
long long l=0,num,n,m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m>>a;
		for(long long j=l;j<=l+m;j++){
			s[j]=a;
		}
		l+=m;
	}
	for(long long i=0;i<=l/2;i++){
		if(s[i]!=s[l-i]){
			num++;
		}
	}
	cout<<num;
	return 0; 
} 
