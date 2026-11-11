#include<bits/stdc++.h> 
using namespace std;
struct node{
	long long a;
	char s;
};
node str[300000];
int n;
long long cnt,l;
bool ishw=0,k=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&str[i].a,&str[i].s);
		if(i!=1&&k){
			if(str[i].s==str[i-1].s) ishw=1;
			else{
				ishw=0;
				k=0;
			}
		}
		l+=str[i].a;
	}
	if(ishw){
		printf("0");
		return 0;
	}
	cnt=l/2;
	printf("%lld",cnt);
	return 0;
}
