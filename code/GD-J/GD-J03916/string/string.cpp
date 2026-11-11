#include<bits/stdc++.h>
using namespace std;
int n,a,t=1,e;
char c,s[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a,&c);
		for(int j=1;j<=a;j++){
			s[t++]=c;
		}
	}
	t--;
	if(t/2==0){
		for(int i=1;i<=t/2;i++){
			if(s[i]!=s[i+t/2]) e++;
		}
	}
	else{
		for(int i=1;i<=t/2;i++){
			if(s[i]!=s[i+t/2+1]) e++; 
		}
	}
	printf("%d",e);
	return 0;
}
