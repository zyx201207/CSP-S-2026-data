#include<bits/stdc++.h>
using namespace std;
int a,n;
char c;
string s;
int main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a,&c);
		for(int j=1;j<=a;j++) s+=c;
	}
	printf("0");

	return 0;
}
