#include<bits/stdc++.h>
using namespace std;
int n,a1[100001],li,ri;
char a2[100001],c1,c2;
long long L,l,b1,b2,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%c%c",&a1[i],&a2[i],&a2[i]);
		L+=a1[i];
	}
	x=L/2;
	l=1;
	li=1;
	ri=n;
	b1=a1[1];
	b2=a1[n];
	c1=a2[1];
	c2=a2[n];
	int LL=L;
	if(L%2==1) L++;
	while(l<L/2){
		if(c1==c2){
			if(b2>b1){
				b2-=b1;
				x-=b1;
				l+=b1;
				b1=a1[++li];
				c1=a2[li];
			}
			else if(b1>b2){
				b1-=b2;
				x-=b2;
				l+=b2;
				b2=a1[--ri];
				c2=a2[ri];
			}
			else{
				x-=b1;
				l+=b1;
				b1=a1[++li];
				b2=a1[--ri];
				c1=a2[li];
				c2=a2[ri];
			}
		}
		else{
			if(b2>b1){
				b2-=b1;
				l+=b1;
				b1=a1[++li];
				c1=a2[li];
			}
			else if(b1>b2){
				b1-=b2;
				l+=b2;
				b2=a1[--ri];
				c2=a2[ri];
			}
			else{
				l+=b1;
				b1=a1[++li];
				b2=a1[--ri];
				c1=a2[li];
				c2=a2[ri];
			}
		}
	}
	if(l>L/2) x+=l-L/2;
	printf("%lld",x);
	return 0;
} 

