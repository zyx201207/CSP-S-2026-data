#include<bits/stdc++.h>
using namespace std;
long long n,ll,ans;
struct nod{
	long long val;
	char c;
};
vector<nod> a,b;
long long x,cnt,mid;
char y;
int main(){
	freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
	scanf("%lld",&n);
	a.push_back({0,'A'});
	for(long long i=1;i<=n;i++){
		scanf("%lld",&x);
		cin>>y;
		ll+=x;
		if(!a.empty()){
			if(a.back().c==y)a.back().val+=x;
			else a.push_back({x,y});
		}
		else a.push_back({x,y});
	}
	long long l=1,r=a.size()-1,l_cnt=a[l].val,r_cnt=a[r].val,lal=0,lar=0;
	ans=(a[l].c!=a[r].c)?min(l_cnt,r_cnt):0;
	while(l+1<r){
		if(l_cnt>=r_cnt){
			lar=r_cnt;
			r--;
			long long uu=r_cnt+a[r].val;
			if(uu>=ll/2){
				uu=l_cnt;
			}
			if(a[l].c!=a[r].c){
				ans+=abs(min(l_cnt,uu)-max(lal,r_cnt));
			}
			r_cnt+=a[r].val;
		}
		else{
			lal=l_cnt;
			l++;
			long long vv=l_cnt+a[l].val;
			if(vv>=ll/2){
				vv=r_cnt;
			}
			if(a[l].c!=a[r].c){
				ans+=abs(min(vv,r_cnt)-max(lar,l_cnt));
			}
			l_cnt+=a[l].val;
		}
	}
	printf("%lld",ans);
	return 0;
} 
