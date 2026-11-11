#include<bits/stdc++.h>
using namespace std;
long long w[500010],k[500010];
struct node{
	int a[500010],len;
	long long t[500010];
	void get(int k){
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
		}
	}
	bool look_line(int k){
		for(int i=1;i<len;i++){
			if(a[i]==k)
				return true;
		}
		return false;
	}
}lines[500010];
pair<int,int> plan[500010];
int c,n,m,d,q;
void read(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		lines[i].get(k[i]);
		lines[i].len=k[i];
	}
	for(int i=1;i<=q;i++){
		cin>>plan[i].first>>plan[i].second;
	}
	return;
}
vector<int> find(int x){
	vector<int> v;
	v.push_back(0);
	for(int i=1;i<=n;i++){ 
		if(lines[i].look_line(x))
			v[0]++,v.push_back(i);
	}
	return v;
}
int solve(int x,int y){
//	CCF, what did you do? I can't write this function. 
	vector line=find(x);
	int ans=1e8;
	for(int i=1;i<=line[0];i++){
		
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read();
	for(int i=1;i<=q;i++){
		cout<<solve(plan[i].first,plan[i].second);
	}
	return 0;
}

