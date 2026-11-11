#include<bits/stdc++.h>
using namespace std;
int tr[8000010][2],st[8000010],id=0;
int su=0;
int n,m,a[200010];
string an;
void bu(string s){
	int fa=0;
	for(int i=0;i<s.size();i++){
		int o=s[i]-'0';
		if(tr[fa][o]==0){
			tr[fa][o]=++id;
			st[id]=1;
		}
		else{
			st[tr[fa][o]]++;
		}
		fa=tr[fa][o];
	}
}
queue<int>p,q;
void qu(int c){
	int ss=0;
	while(p.size()){
		int t=p.front();
		p.pop();
		q.push(t);
		if(tr[t][1]!=0)ss+=st[tr[t][1]];
	}
	if(ss<m){
		while(q.size()){
			int t=q.front();
			q.pop();
			if(tr[t][0]!=0){
				p.push(tr[t][0]);
			}
			if(tr[t][1]!=0)p.push(tr[t][1]);
		}
	}
	else{
		su+=(1<<(c-1));
		while(q.size()){
			int t=q.front();
			q.pop();
			if(tr[t][1]!=0)p.push(tr[t][1]);
		}
	}
	if(c!=1)qu(c-1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		string s;
		int o=a[i];
		while(o){
			s=char(o%2+'0')+s;
			o/=2;
		}
		while(s.size()<30){
			s='0'+s;
		}
		bu(s);
	}
	p.push(0);
	qu(30);
	cout<<su;
	return 0;
}
