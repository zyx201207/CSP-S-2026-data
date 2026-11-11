#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define ull unsigned long long 
#define fre
//#define int long long
const int maxn=3e5+5;
//存段枚举，空间降到O(n)，最低
// 时间的话，O(n)
ull cnt;//个数 
struct p{//段落 
	char a;//字符
	ll d;//位数 
}pr[maxn];
signed main(){
	#ifdef fre
		freopen("string6.in","r",stdin);
		freopen("string.out","w",stdout);
	#endif
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>pr[i].d>>pr[i].a;
	} 
	for(int i=1,j=n;i<j;){//双向奔赴！
		int tot=min(pr[i].d,pr[j].d);
		if(pr[i].a!=pr[j].a)cnt+=tot;
		pr[i].d-=tot;
		pr[j].d-=tot;
		if(pr[i].d==0)i++;
		if(pr[j].d==0)j--;
	}
	cout<<cnt;
}
