#include<bits/stdc++.h>
using namespace std;
long long n,s=0,a,t=1,l=0;
char b[1000000000000],c;
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		l+=a;
		for(long long j=1;j<=a;j++){
			b[t]=c;
			t++;
		}
	}
	for(long long i=1,j=l;j>i;i++,j--){
		if(b[i]!=b[j])s++;
	}cout<<s;
	return 0;
}
/*
di yi ci can jia csp-j,gan jve zi ji mei zuo hao shen me zhun bei.
shen zhi lian freopen dou shi lin shi bao fuo jiao bei de.
ba ce shi wen jian tuo dao wen jian jia li hou zai yun xing fa xian mei you .out de wen jian.qwq
suan le ba, cai chu yi, you de shi ji hui......
ke shi ce bu liao da yang li a!!!!!!!!!!!!!!qwq

















































wo yao shang mi huo xing wei da shang
*/
