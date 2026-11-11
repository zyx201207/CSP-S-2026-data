#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,INF=LLONG_MAX,P=13331;
int read(){
	int x=0,f=1;
	char c=getchar();
	while('0'>c||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int c1,c2;
char s1[10],s2[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld%s%lld%s",&c1,s1+1,&c2,s2+1);
	if(c1==c2){
		printf("1");
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			printf("1");
			if((s1[3]<='C'&&s2[3]<='C')||(s1[3]>'C'&&s2[3]>'C')){
				printf("1");
				if((s1[3]<='C'&&s2[3]<='C'&&abs((int)s1[3]-(int)s2[3])==1ll)||(s1[3]>'C'&&s2[3]>'C'&&abs((int)s1[3]-(int)s2[3])==2ll))printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
}
