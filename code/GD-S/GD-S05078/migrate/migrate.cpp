#include "bits/stdc++.h"
#define ll long long
#define By_mumu return 0
using namespace std;
ll c,t,n,d,x[2000010],ans[2000010],num;

struct stu{
	ll ch;
	ll x,y;
}a[2000010];

void findd(ll s,ll e,ll t,ll fin){
	if(s==fin){
//		cout << "t:"<< t << endl;
		ans[t]++;
		return;
	}
		for(int j=s+1;j<=e;j++)
		{
			if(x[j]-x[s] <= d)
			{
//				cout << "ii:" << s << " jj:" << j << endl;
				findd(j,e,t+1,fin);
			}
		}
		
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	cin >> c >> t;
	scanf("%lld%lld",&c,&t);
	while(t--){
//		cin >> n >> d;
		scanf("%lld%lld",&n,&d);
		num=0;
		for(int i=1;i<=n;i++){
//			cin >> x[i];
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				memset(ans,0,sizeof(ans));
//				cout << "i:" << i << " j:" << j << endl;
				findd(i,j,0,j);
				for(int i=1;i<=n;i++){
					if(ans[i]==0) continue;
					else if(ans[i]==2) {num++;break;}
					else break;
				}
			}
		}
		cout << num << endl;
	}
	By_mumu;
} 
