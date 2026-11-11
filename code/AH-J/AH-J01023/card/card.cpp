#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,maxn=-0x3f3f3f3f,pos;
int a[200005],t[100005],vis[200005];
int ans[200005];
int sum[200005],c[200005],ma[200005];
long long anssum[200005];
map<int,int>mp;

struct node{
	int x,i;
};
struct edge{
	int x,y;
}b[200005];
bool cmp1(edge x,edge y){
	if(x.x!=y.x){
		return x.x<y.x;
	}else{
		return x.y<y.y;
	}
}
bool cmp(int x,int y){
	return x<y;
}
queue<node>q;
vector<int>g[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	//memset(ma,0x3f,sizeof(ma));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<int(g[i].size())-1;j++){
			int x=g[i][j];
			int y=g[i][j+1];
			cnt++;
			b[cnt]={x,y};
			c[cnt]=x;
			ans[x]-=x;
			ans[y]+=x;
		}
	}
	sort(b+1,b+1+cnt,cmp1);
	sort(c+1,c+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int x=lower_bound(c+1,c+1+cnt,c[i])-c;
		x--;
		//cout<<b[i].x<<" "<<b[i].y<<" "<<c[i]<<endl;
		for(int j=1;j<=x;j++){
			if(b[j].y>b[i].x){
				ma[i]=max(ma[i],b[j].x);
			}
		}
		if(ma[i]==0x3f3f3f3f)ma[i]=0;
		ans[b[i].x]+=ma[i];
		ans[b[i].y]-=ma[i];
	}
	int pos=0;
	for(int i=1;i<=n;i++){
		pos+=ans[i];
		anssum[a[i]]+=i+pos;
		//cout<<pos<<" ";
	}
	/*
	for(int i=1;i<=n;i++){
		mp[a[i]]++;
		t[i]=mp[a[i]];
		if(t[i]>1){
			cnt++;
			if(maxn<i){
				maxn=i;
				pos=a[i];
			}
			//maxn=max(maxn,i);
		}
	}
	* *
	for(int i=n;i>=1;i--){
		if(vis[a[i]]==0&&mp[a[i]]>1){
			q.push({a[i],i});
		}
	}
	//cout<<maxn;
	for(int i=maxn;i<=n;i++){
		anssum[a[i]]++;
	}
	int l=maxn;
	for(int i=1;i<=n;i++){
		mp[a[i]]--;
		if(mp[pos]<=1){
			l=i+1;
			while(!q.empty()){
				node t=q.front();
				q.pop();
				if(mp[t.x]>1){
					l=max(l,t.i);
					break;
				}
			}
			cout<<l<<endl;
			sum[l]+=1;
			sum[n+1]-=1;
		}else{
			sum[l]+=1;
			sum[n+1]-=1;
		}
	}
	*
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=sum[i];
		anssum[a[i]]+=ans;
	}
	* */
	for(int i=1;i<=m;i++){
		cout<<anssum[i]<<" ";
	}
	
	return 0;
}
