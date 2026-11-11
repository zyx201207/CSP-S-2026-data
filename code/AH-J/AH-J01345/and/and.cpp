#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int b[200010][40];
set<int> s[40];
int ans[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin >>a[i];	
		int x=a[i],l=0;
		while(x>0){
			b[i][++l]=x&1;
			x>>=1;
		}
		maxn=max(maxn,l);
	}
	int p=0;
	for(int i=1;i<=maxn;i++){
		for(int j=1;j<=n;j++){
			if(b[j][i]==1)s[i].insert(j);
		}
		if((int)s[i].size()>=m)p=i;
	}
	ans[p]=1;
	set<int> pre=s[p];
	set<int> now;
	for(int i=p-1;i>=1;i--){
		if((int)s[i].size()<m)continue;
		now.clear();
		for(set<int>::iterator j=s[i].begin();j!=s[i].end();j++){
			if(pre.count(*j))now.insert(*j);
		}
		if((int)now.size()<m)continue;
		ans[i]=1;
		pre=now;
	}
	long long ss=0;
	for(int i=1;i<=p;i++){
		if(ans[i])
		ss+=1<<(i-1);
	}
	cout<<ss;
	return 0;
} 

