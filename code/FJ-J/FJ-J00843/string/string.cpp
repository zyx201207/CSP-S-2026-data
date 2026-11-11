#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long a,ans;
int n;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	/*提交时去掉freopen！！！*/
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a,&c);
		for(int j=1;j<=a;j++)s.push_back(c);
	}
	long long l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r])ans++;
		l++,r--;
		}
	printf("%lld\n",ans);
	return 0;
}
