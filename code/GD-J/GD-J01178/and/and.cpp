#include<bits/stdc++.h>
using namespace std;
struct e{
	int a,v[31];
	bool bj;
}num[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt,val,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>num[i].a;
		val=num[i].a,cnt=-1;
		while(val)
			num[i].v[++cnt]=val%2,val/=2;
	}
	for(int i=30;i>=0;--i){
		cnt=0;
		for(int j=1;j<=n;++j)
			if(num[j].v[i]==1&&!num[j].bj)
				++cnt;
		if(cnt>=m){
			ans+=pow(2,i);
			for(int j=1;j<=n;++j)
				if(num[j].v[i]==0)
					num[j].bj=1;
		}
	}
	cout<<ans;
	return 0;
}
