#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[200000+10],sum[200000+10];
string cnt[200000+10];
vector<LL> v;
string to_x(LL x){
	string s;
	while(x){
		s+=x%2+'0';
		x/=2;
	}
	while(s.size()!=30) s+='0';
	reverse(s.begin(),s.end());
	return s;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=1;
		cnt[i]=to_x(a[i]);
	}
    for(int i=0;i<30;i++){
		vector<LL> t;
		for(int j=1;j<=n;j++){
			if(cnt[j][i]=='1' && sum[j]) t.push_back(j);
		}
		if(LL(t.size())>=m){
			v=t;
			memset(sum,0,sizeof sum);
			for(int j=0;j<LL(v.size());j++) sum[v[j]]=1;
		}
	}
	LL k=a[v[0]];
	for(int i=0;i<LL(v.size());i++) k=k&a[v[i]];
	printf("%lld",k);
    return 0;
}
