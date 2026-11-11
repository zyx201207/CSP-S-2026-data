#include<bits/stdc++.h>
using namespace std;
int n,m,a,ans;
vector<string> v;
string s,cmp;
string add(string s1,string s2){
	string x;
	int l=min(s1.size(),s2.size());
	for(int i=0;i<l;i++){
		if(s1[i]!=s2[i]) return 0;
		x+=s1[i];
	}return x;
}
void dfs(int num,int x){
	if(num>m){
		if(s>cmp) cmp=s;
	}if(x>n) return ;
	dfs(num,x+1);
	s=add(s,v[x]);
	dfs(num+1,x+1);
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		while(a>0){
			v[i]=char(a%2)+v[i];
			a/=2;
		}
	}dfs(0,1);
	int l=cmp.size()-1,p=1;
	for(int i=0;i<=l;i++){
		ans+=cmp[i]*p;
		p*=2;
	}printf("%d\n",ans);
	return 0;
}
