#include<bits/stdc++.h>
using namespace std;
vector<int>sta[500005];
vector<int>line[500005];
int w[500005];//地铁口到站厅
int t[500005][10];//站厅到站台 
int r[100005][2];//
int pd[500005];
struct u{
	int now;
	int to;
	int time;
	int line;
};
u uu(int a,int b,int c,int d){
	u tt;
	tt.now=a,tt.to=b,tt.time=c,tt.line=d;
	return tt;
}
int cnt(int f,int e,int l){
	queue<u>q;
	int ans=100866767;
	u fr;
	fr=uu(f,e,w[f],l);
	q.push(fr);
	while(!q.empty()){
		u z=q.front();
		q.pop();
		int zn=z.now;
		if(zn=e){
			ans=min(ans,(z.time));
			continue;
		}
		if(pd[zn])continue;
		if(sta[zn].size()>1){
			for(int h=0;h<sta[zn].size();h++) q.push(uu(zn,e,z.time+t[zn][sta[zn][h]]+t[zn][z.line],sta[zn][h]));
			
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int s; 
			cin>>s;
			cin>>t[s][0];
			t[s][1]=j;
			line[j].push_back(s);
			sta[s].push_back(j);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i][0]>>r[i][1];
		int anss=100866767;
		for(int j=0;j<sta[r[i][0]].size();j++){
			anss=min(anss,cnt(r[i][0],r[i][1],sta[r[i][0]][j]));
		}
		int aaaa=anss+w[r[i][1]];
		cout<<aaaa;
	}
	
	return 0;
}
