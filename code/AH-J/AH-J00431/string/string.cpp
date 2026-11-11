#include<bits/stdc++.h>
using namespace std;

int n,x,cnt;
char c;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&x,&c);
		for(int j=1;j<=x;j++)s+=c;
	}
	int lens=s.size();
	for(int i=0;i<lens/2;i++){
		if(s[i]!=s[lens-i-1])cnt++;
	}
	printf("%d",cnt);
	return 0;
}
