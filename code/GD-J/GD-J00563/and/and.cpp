#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+100;
int n,m;
int ans=1,sum,po;
stack<int> id;
int a[N];
vector<int> b[60];
void dfs(int k,vector<int> b){
	vector<int> c[60];
	for(auto i : b){
		int p=a[i],l=-1;
		while(p){
			++l;
			if(p%2)c[l].push_back(i);
			p/=2;
		}		
	}
	for(int i=k-1;i>=0;i--)
		if(c[i].size()>=m){id.push(i);break;}
	if(id.top()==k)return;
	dfs(id.top(),c[id.top()]);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		int p=a[i],l=-1;
		while(p){
			++l;
			if(p%2==1)b[l].push_back(i);
			p/=2;
		}		
	}
	for(int i=31;i>=0;i--)if(b[i].size()>=m){id.push(i);break;}
	if(id.empty()){
		printf("0");
		return 0;
	}
	dfs(id.top(),b[id.top()]);
	while(!id.empty()){
		if(po!=id.top())po++,ans<<=1;
		else{sum+=ans;id.pop();}
	}
	printf("%lld",sum);
	return 0;
}
