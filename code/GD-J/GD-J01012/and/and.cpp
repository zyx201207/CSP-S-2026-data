#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	int sum;
}s[20010];
bool cmp(node x,node y){
	if(x.sum==y.sum){
		return x.a>y.a;
	}else{
		return x.sum>y.sum;
	}
}
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].a;
		long long p=s[i].a;
		while(p){
			if(p&1)s[i].sum++;
			p>>=1;
		}
	}
	sort(s+1,s+n+1,cmp);
	for(int i=2;i<=m;i++){
		ans=s[i].a&s[i-1].a;
	}
	cout<<ans;
	return 0;
}
