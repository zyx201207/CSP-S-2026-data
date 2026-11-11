#include<bits/stdc++.h>
using namespace std;
int n,a;int a1=0,a2=0;
long long al[25];
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	if(n==1){
		printf("0");
		return 0;
	}else if(n==2){
		char c1,c2;
		scanf("%d%s%d%s",&a1,&c1,&a2,&c2);
		if(c1!=c2) printf("%d",min(a1,a2));
		else printf("0");
		return 0;
	}
	while(n--){
		scanf("%d%c",&a,&c);
		al[c-'0']+=a;
		
	}
	return 0;
} 
