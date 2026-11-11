#include <bits/stdc++.h>
using namespace std;
void ones(bool *l,int num){
	int i=0;
	while(num){
		l[i]=num%2;
		num>>=2;
		i++;
	}
}
bool binnum[20121][32];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int i,ans=0x7FFFFFFF,ai;
	if(m==1)ans=-1;
	scanf("%d%d",n,m);
	for(int i=0;i<n;i++){
		scanf("%lld",&ai);
		ones(binnum[i],ai);
		if(m==1)ans=ans>ai?ans:ai;
		else ans&=ai;
	}
	printf("%d",ans);
	return 0;
}
