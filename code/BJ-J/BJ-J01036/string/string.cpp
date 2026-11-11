#include <bits/stdc++.h>
using namespace std;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	int x;
	char c;
	long long tch=0;
	for(int i=0;i<n;i++){
		scanf("%d %c",&x,&c);
		for(int j=0;j<x;j++){
			s+=c;
		}
	}
	long long l=s.size();
	s1=s;
	reverse(s1.begin(),s1.end());
	for(int i=l/2;i<l;i++){
		if(s1[i]!=s[i])tch++;
	}
	printf("%lld",tch);
	return 0;
}
