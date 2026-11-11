#include<bits/stdc++.h>
using namespace std;
const int T=1e9+5;
int n;
char t[T];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	int h=0;
	for(int i=1; i<=n; i++){
		int a;
		char c;
		scanf("%d %c",&a,&c);
		for(int j=1; j<=a; j++){
			t[h++]=c;
		}
	}
	int sum=0;
	for(int i=0,j=h-2; i<=j; i++,j--){
		if(t[i]!=t[j]){
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
} 
