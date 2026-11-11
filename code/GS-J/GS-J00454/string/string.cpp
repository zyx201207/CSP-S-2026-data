#include<bits/stdc++.h>
using namespace std;
const int N=2e5+25;
int n,a;
string s;
long long len,mid,ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a,&c);
		len+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	mid=len/2+len%2;
	for(int i=mid;i<len;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
