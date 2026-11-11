#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,a[N],ans;
vector<int> e[N],g[N];
int fe[N],fg[N];
void cl(){
	fill(fe,fe+n+5,0);
	fill(fg,fg+n+5,0);
	fill(e,e+n+5,vector<int>{});
	fill(g,g+n+5,vector<int>{});
	ans=0;
	fill(a,a+n+5,0);
}
int ck(vector<int> &s1,vector<int> &s2){
	int m=(int)s1.size();
	int fl=0;
	for(int i=0;i<m;i++){
		if(s1[i]-s2[i]==0){
			if(fl==1) fl=2;
		}
		else if(s1[i]-s2[i]==1){
			if(fl==2||fl==1) return 0;
			if(fl==0) fl=1;
		}
		else{
			return 0;
		}
	}
	if(fl==1||fl==2) return 1;
	return 0;
}
void collect1(int i,int j,vector<int> &res){
	int u=fe[i];
	while(u!=0&&u<j){
//		cerr<<"collect1:"<<u<<"\n";
		res.push_back(u);
		u=fe[u];
	}
}
void collect2(int j,int i,vector<int> &res){
	int u=fg[j];
	while(u!=0&&u>i){
//		cerr<<"collect2:"<<u<<"\n";
		res.push_back(u);
		u=fg[u];
	}
}
void calc(int l,int r){
//	cerr<<"calc:"<<l<<" "<<r<<"\n";
	int pos=l;
	for(int i=l;i<r;i++){
		while(pos!=r&&a[pos+1]-a[i]<=d){
			pos++;
		}
		e[i].push_back(pos);
		e[pos].push_back(i);
		fe[i]=pos;
//		cerr<<"fe:"<<i<<" "<<pos<<"\n";
	}
	pos=r;
	for(int i=r;i>l;i--){
		while(pos!=l&&a[i]-a[pos-1]<=d){
			pos--;
		}
		g[i].push_back(pos);
		g[pos].push_back(i);
		fg[i]=pos;
//		cerr<<"fg:"<<i<<" "<<pos<<"\n";
	}
//	cerr<<"*\n";
	for(int i=l;i<=r;i++){
		for(int j=l+1;j<=r;j++){
			vector<int> s1,s2;
//			cerr<<"cal:"<<i<<" "<<j<<"\n";
			collect1(i,j,s1);
			collect2(j,i,s2);
			reverse(s2.begin(),s2.end());
			if(ck(s1,s2)) ans++;
		}
	}
}
void sol(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int las=1;
	for(int i=1;i<n;i++){
		if(a[i]+d<a[i+1]){
			calc(las,i);
			las=i+1;
		}
	}
	calc(las,n);
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int cs,ct=1;
	cin>>cs>>ct;
	while(ct--){
		sol();
		cl();
	}
	/*
	#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,a[N],ans;
vector<int> e[N],g[N];
int fe[N],fg[N];
void cl(){
	fill(fe,fe+n+5,0);
	fill(fg,fg+n+5,0);
	fill(e,e+n+5,vector<int>{});
	fill(g,g+n+5,vector<int>{});
	ans=0;
	fill(a,a+n+5,0);
}
int ck(vector<int> &s1,vector<int> &s2){
	int m=(int)s1.size();
	int fl=0;
	for(int i=0;i<m;i++){
		if(s1[i]-s2[i]==0){
			if(fl==1) fl=2;
		}
		else if(s1[i]-s2[i]==1){
			if(fl==2||fl==1) return 0;
			if(fl==0) fl=1;
		}
		else{
			return 0;
		}
	}
	if(fl==1||fl==2) return 1;
	return 0;
}
void collect1(int i,int j,vector<int> &res){
	int u=fe[i];
	while(u!=0&&u<j){
//		cerr<<"collect1:"<<u<<"\n";
		res.push_back(u);
		u=fe[u];
	}
}
void collect2(int j,int i,vector<int> &res){
	int u=fg[j];
	while(u!=0&&u>i){
//		cerr<<"collect2:"<<u<<"\n";
		res.push_back(u);
		u=fg[u];
	}
}
void calc(int l,int r){
//	cerr<<"calc:"<<l<<" "<<r<<"\n";
	int pos=l;
	for(int i=l;i<r;i++){
		while(pos!=r&&a[pos+1]-a[i]<=d){
			pos++;
		}
		e[i].push_back(pos);
		e[pos].push_back(i);
		fe[i]=pos;
//		cerr<<"fe:"<<i<<" "<<pos<<"\n";
	}
	pos=r;
	for(int i=r;i>l;i--){
		while(pos!=l&&a[i]-a[pos-1]<=d){
			pos--;
		}
		g[i].push_back(pos);
		g[pos].push_back(i);
		fg[i]=pos;
//		cerr<<"fg:"<<i<<" "<<pos<<"\n";
	}
//	cerr<<"*\n";
	for(int i=l;i<=r;i++){
		for(int j=l+1;j<=r;j++){
			vector<int> s1,s2;
//			cerr<<"cal:"<<i<<" "<<j<<"\n";
			collect1(i,j,s1);
			collect2(j,i,s2);
			reverse(s2.begin(),s2.end());
			if(ck(s1,s2)) ans++;
		}
	}
}
void sol(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int las=1;
	for(int i=1;i<n;i++){
		if(a[i]+d<a[i+1]){
			calc(las,i);
			las=i+1;
		}
	}
	calc(las,n);
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate3.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int cs,ct=1;
	cin>>cs>>ct;
	while(ct--){
		sol();
		cl();
	}
}
*/
}
