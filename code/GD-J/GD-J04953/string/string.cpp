#include<bits/stdc++.h>
using namespace std;
int n,a,b=0;
char c;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a,&c);
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])b++;
	}
	printf("%d",b);
	return 0;
} 
