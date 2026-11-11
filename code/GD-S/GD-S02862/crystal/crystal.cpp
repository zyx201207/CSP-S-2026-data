#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,res=-0x3f3f3f3f;
int s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	sort(s+1,s+n+1);
	int l=s[1],r=s[n];
	if(l==r){
		printf("%lld",n);
		return 0;
	}
	for(int e=1;e<=n;e++){
		if(e!=1&&s[e]==s[e-1]){
			continue;
		}
		int x=s[e];
		int rt=upper_bound(s+1,s+n+1,x)-(s+1),lrt=lower_bound(s+1,s+n+1,x)-(s+1);//<=最右边的,<最右边的 
		int mm=m;
		int minl=lrt;//取到的最左边 
		for(int i=lrt;i;i--){
			int ct=x-s[i];
			if(mm>=ct){
				mm-=ct;
				minl=i;
			}
			else{
				break;
			}
		}
		//实际上取到的区间是[minl,rt]
		res=max(res,rt-minl+1);
	}
	printf("%lld",res);
	return 0;
}
/*
5 8
-4 -1 2 2 7

4

315275
*/
