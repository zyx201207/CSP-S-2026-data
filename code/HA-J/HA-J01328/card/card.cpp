#include<bits/stdc++.h>
#define endl '\n'
#define getchar getchar_unlocked
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int n,m,r,a[500005],ans[500005];
map<int,int>vis;
vector<int>s;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++){
		r=i;
		s.clear();
		vis.clear();
		for(int j=i;j<=r;j++){
			if(vis[a[j]]!=0){
				r++;
				vis[a[j]]=j;
				s.push_back(a[j]);
			}
			else{
				r=vis[a[j]];
				s.push_back(a[j]);
				for(int k=r;k<=n;k++){
					vis[s[k]]=0;
					s.pop_back();
				}
			}
		}
		for(int j=0;j<s.size();j++)
			ans[s[j]]++;
		for(int j=0;j<r-i+1;j++)
			cout<<s[j]<<" ";
			cout<<endl;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
// 寫 不 出 來 這 把 給 了 
