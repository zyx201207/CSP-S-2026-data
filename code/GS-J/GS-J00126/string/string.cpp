#include<bits/stdc++.h>
using namespace std;

int n;
char s[1000000001];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	int k = 0;
	for(int i = 1;i <= n;i++){
		int x;
		char abc,def;
		char c;
		scanf("%d%c%c%c",&x,&abc,&c,&def);
		for(int i = k + 1;i <= k + x;i++){
			s[i] = c;
		}
		k += x;
	} 
	int sum = 0;
	for(int i = 1;i <= k / 2;i++){
		if(s[i] != s[k - i + 1]){
			sum++;
		}
	}
	printf("%d",sum);
}
