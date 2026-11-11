#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,char> PLC;
const int N=2e5+5;
LL n,sum_len,ans;
bool flag=false,st=true;
struct ziduan{
	LL len;
	char a;
}x[N];
stack<PLC> l;
deque<PLC> r;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&x[i].len,&x[i].a);
		sum_len+=x[i].len;
	}
	if(sum_len%2) flag=true;	
	sum_len/=2;
	for(int i=1;i<=n;i++){
		if(x[i].len>sum_len&&st){
			l.push({sum_len,x[i].a});
			if(flag) r.push_back({x[i].len-sum_len-1,x[i].a});
			else r.push_back({x[i].len-sum_len,x[i].a});
			st=false;
		}else{
			if(st) l.push({x[i].len,x[i].a});
			else r.push_back({x[i].len,x[i].a});
			sum_len-=x[i].len;
		}
	}	
	while(l.size()&&r.size()){		
		LL lf=l.top().first,rf=r.front().first;
		char ls=l.top().second,rs=r.front().second;
		l.pop(),r.pop_front();
		if(ls==rs){
			if(lf>rf) l.push({lf-rf,ls});
			if(lf<rf) r.push_front({rf-lf,rs});
		}else{
			ans+=min(lf,rf);			
			if(lf>rf) l.push({lf-rf,ls});
			if(lf<rf) r.push_front({rf-lf,rs});
		}
	}
	cout<<ans<<endl;
	return 0;
}
//Trick||Treat!
