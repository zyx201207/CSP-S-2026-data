#include<bits/stdc++.h>
using namespace std;
int n;
string s="\0";
long long l=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		l+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	long long i=1;
	long long cnt=0;
	while(i<=l/2){
		if(s[i]!=s[l+1-i])cnt++;
		i++;
	}
	printf("%lld",cnt);
	return 0;
}
