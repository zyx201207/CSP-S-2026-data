#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n,m,cnt;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&m,&x);
		for(int j=1;j<=m;j++){
			s1 += x;
		}
	}
	s2 = s1;
	reverse(s2.begin(),s2.end());
	for(int i=0;i<(s1.size()+1)/2;i++){
		if(s1[i] != s2[i]){
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
} 
