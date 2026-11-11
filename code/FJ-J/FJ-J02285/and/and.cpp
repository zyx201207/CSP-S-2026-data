#include<bits/stdc++.h> 
using namespace std;
struct node{
	long long num;
	string s;
};
int n,m;
node a[200005];
long long q[30];
string ans;
vector<int> g;
void dfs(int now){
	for(int i=now-1;i>=0;i--){
		vector<int> v1;
		for(int j=0;j<g.size();j++){
			int id=g[j];
			if(a[id].s[i]=='1'){
				v1.push_back(id);
			}
		}
		if(v1.size()>=m){
			g.clear();
			for(int i=0;i<v1.size();i++)g.push_back(v1[i]);
			ans[i]='1';
			//cout<<i<<endl;
			dfs(i);
			return;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(long long i=0,j=1;i<30;i++,j*=2)q[i]=j,ans[i]='0';
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].num);
		g.push_back(i);
		long long sum=a[i].num;
		a[i].s="";
		int j=29;
		while(j>=0){
			if(sum>=q[j]){
				sum-=q[j];
				a[i].s="1"+a[i].s;
			}else{
				a[i].s="0"+a[i].s;
			}
			j--;
		}
			//cout<<a[i].s<<endl;
	}
	dfs(30);
	long long ans1=0;
	for(int i=0;i<30;i++){
		if(ans[i]=='1'){
			//cout<<i<<endl;
			ans1+=q[i];
		}
	}
	printf("%lld",ans1);
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

*/
