#include<bits/stdc++.h>
#define int long long
const int N=5*1e5+5;
using namespace std;
int n,m,ans;
int b[N],cnt;
unordered_map<int,int>mp;
int rdrd(){
	int n=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		n=n*10+c-'0';
		c=getchar();
	}
	return n*f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rdrd();m=rdrd();
	for(int i=1;i<=n;++i){
		int x=rdrd();
		if(!mp[x]){
			b[++cnt]=x;
		}
		mp[x]++;
	}
	sort(b+1,b+cnt+1);
	for(int i=1;i<=cnt;++i){
		int j=i,num=mp[b[i]],nm=m;
		if(i==1){
			ans=1;
			continue;
		}
		while(nm>=0&&j>0){
			if(nm==0)break;
			if(j==i){
				j--;continue;
			}
			int u=abs(b[i]-b[j]);
			int v=mp[b[j]];
			//cout<<num<<"num "<<u<<"u "<<v<<"v "<<nm<<"nm "<<i<<"i "<<j<<"j "<<"\n";
			if(nm>=u*v){
				nm-=u*v;
				num+=v;
				j--;
			}else{
				int p=floor(nm/u);
				num+=p;
				break;
			}
			//cout<<num<<"num "<<j<<"j "<<b[i]<<" "<<b[j]<<" "<<nm<<"nm "<<"\n";
		}
		ans=max(ans,num);
	}
	cout<<ans;
	/*
	5 5
	1 2 4 8 9
	
	5 8
	-3 -1 2 2 7
	*/
	return 0;
}
