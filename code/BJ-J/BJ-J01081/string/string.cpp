#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=200020;
struct STR{
	int a;
	char c;
};
STR str[maxn];
long long solve(long long l,long long r,int i1,int i2){
	long long cnt=0;
	while(l<=r && i1<i2){
		int len1=min(str[i1].a,str[i2].a);
		str[i1].a-=len1;
		str[i2].a-=len1;
		if(str[i1].c!=str[i2].c){
			cnt+=1ll*len1;
		}
		l+=len1,r-=len1;
		if(str[i1].a<=0){
			i1++;
		}
		if(str[i2].a<=0){
			i2--;
		}
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	long long L=0;
	
	for(int i=1;i<=n;i++){
		cin>>str[i].a>>str[i].c;
		L+=str[i].a;
	}
	
	long long cnt=solve(1,L,1,n);
	printf("%lld\n",cnt);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}