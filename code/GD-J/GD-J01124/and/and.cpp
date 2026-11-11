#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo i,j,k,l,n,m,mm,r,s,ss;
vector<lo> v[30];
vector<lo> f,g;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&mm);
		g.push_back(i);
		for(j=29;j>=0;j--){
			if((1ll<<j)&mm)v[j].push_back(i);
		}
	}
	for(i=29;i>=0;i--){
		if(v[i].size()<m)continue;
		f.clear();
		j=0;
		for(auto val:g){
			while(j<v[i].size()&&v[i][j]<val)j++;
			if(j<v[i].size()&&v[i][j]==val)f.push_back(val);
		}
		if(f.size()<m)continue;
		g.clear();
		for(auto val:f)g.push_back(val);
		ss+=(1ll<<i);
	}
	printf("%lld",ss);
	return 0;
}

