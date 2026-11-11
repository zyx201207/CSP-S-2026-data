#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,start=0;
	string s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		char c;
		scanf("%d %c",&a,&c);
		for (int i=1;i<=a;i++){
			s[start]=c;
			start++;
		}
	}
	int cnt=0;
	for(int i=0;i<start;i++){
		if(s[i]!=s[start-i]){
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
} 

