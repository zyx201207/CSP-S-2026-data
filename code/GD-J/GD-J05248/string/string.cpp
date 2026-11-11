#include<bits/stdc++.h>
using namespace std;
int n,p=1,q=1,cnt1=0,cnt2=0;
long long ans=0;
struct D{int a;char c;}d1[200001],d2[200001];
vector<D>v[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&d1[i].a,&d1[i].c);
		d2[n+1-i].a=d1[i].a;
		d2[n+1-i].c=d1[i].c;
	}
	for(int i=1;i<=n;i++)v[i].push_back({d1[i].a,d1[i].c});
	cnt1=d1[p].a;cnt2=d2[q].a;
	while(p<=n&&q<=n){
		if(cnt1>=cnt2){
			v[p].push_back({cnt2,d2[q].c});
			cnt1-=cnt2;
			q++;cnt2=d2[q].a;
			if(cnt1==0){
				p++;cnt1=d1[p].a;
			}
		}
		else{
			v[p].push_back({cnt1,d2[q].c});
			cnt2-=cnt1;
			p++;cnt1=d1[p].a;
		}
	}
	for(int i=1;i<=n;i++){
		char u=v[i][0].c;
		for(int j=1;j<v[i].size();j++){
			ans+=u==v[i][j].c?0:v[i][j].a;
		}
	}
	printf("%lld",ans/2);
	return 0;
}
