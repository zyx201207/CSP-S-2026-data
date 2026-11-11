#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100001];
map<int,int> mp;
set<int> st; 
void work(int p){
	int ans=0;
	string s="";
	string p2=to_string(p);
	queue<int> q;
	for(int i=p;i<=n;i++){
		string t=to_string(a[i]);
		if(s.find(t)==-1){
			q.push(a[i]);
			s=s+" "+t;
		}
		else{
			int o=0,u=0;
			o=s.find(t);
			s.erase(o+1);
			queue<int> x,y;
			x=q;
			while(x.size()){
				int w=x.front();
				x.pop();
				if(u==0&&w!=a[i]) y.push(w);
				else if(w==a[i]) u=1;
			}
			q=y;
			q.push(a[i]);
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=' ') mp[s[i]-'0']++;
	}
}
main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		work(i);
	}
	for(int i=1;i<=m;i++) cout<<mp[i]<<" ";
}
