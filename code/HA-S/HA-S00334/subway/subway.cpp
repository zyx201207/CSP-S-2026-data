#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[510000],temp,mp[510][510],a1,a2,ans;
struct nd{
	long long k;
	vector<long long> pts;
	vector<long long> va;
} line[510];
struct point{
	vector<long long> ls;
} pt[510000];
int belonging(int x,int y){
	for(int i=0;i<line[y].pts.size();i++){
		if(line[y].pts[i]==x) return line[y].va[i];
	}
	return 0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(mp,1,sizeof(mp));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&line[i].k);
		for(int j=1;j<=line[i].k;j++){
			scanf("%lld",&temp);
			line[i].pts.push_back(temp);
			pt[temp].ls.push_back(i);
			scanf("%lld",&temp);
			line[i].va.push_back(temp);
		}
	}
	for(int i=1;i<=n;i++) mp[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int q=0;q<=line[i].pts.size();q++){
				int tp1=belonging(line[i].pts[q],j);
				if(tp1!=0){
					mp[i][j]=min(mp[i][j],tp1+line[i].va[q]);
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) cout<<mp[i][j]<<" ";
//		cout<<"\n";
//	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&a1,&a2);
		ans=999999999;
		for(int j=0;j<pt[a1].ls.size();j++){
			for(int k=0;k<pt[a2].ls.size();k++){
				ans=min(ans,mp[pt[a1].ls[j]][pt[a2].ls[k]]+belonging(a1,pt[a1].ls[j])+belonging(a2,pt[a2].ls[k]));
			}
		}
		ans=ans+w[a1]+w[a2];
		cout<<ans<<"\n";
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
