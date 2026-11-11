#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int maxn=1e6*2+100;
int tstid,T;
int n,m,a[maxn],way[maxn],st[maxn],la[maxn],v[maxn];
priority_queue<pair<int,int> >vm;
void solveA(){
	int s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int last=i;
		st[i]=0,la[i]=i;
		while(!vm.empty()) vm.pop();
		for(int j=i+1;j<=n;j++)
		{
			while(a[j]-a[last]>m) last++;
			if(j==last) 
			{
				la[j]=j;
				continue;
			}
			
			st[j]=st[last]+1;
			v[st[j]]=0;
			la[j]=last;
		}
		int nl=i;
		for(int j=i+1;j<=n;j++)
		{
			if(vm.empty()) vm.push({v[st[j]],st[j]});
			else if(vm.top().first<v[st[j]]) vm.push({v[st[j]],st[j]});
			while((st[j]-st[nl])*m<a[j]-a[nl]) v[st[nl]]-- , nl++;
			while(!vm.empty())
			{
				int sec=vm.top().second;
				if(v[vm.top().second]!=vm.top().first)
				{
					vm.pop();
					vm.push({v[sec],sec});
				}
				else break;
			}
			
			if(vm.top().first>2) break;
			if(vm.top().first==2) 
			{
				int ok=0,cnt=0;
				for(int i=1;i<=n;i++)
				{
					if(v[i]) cnt++;
					if(v[i]==1) ok++;
				}
				if(cnt-ok==1&&ok!=0) continue;
				s++;
				//cout<<i<<" "<<j<<'\n';
			}
			v[st[j]]++;
		}
//		for(int j=i;j<=n;j++) cout<<st[j]<<" ";cout<<'\n';
//		for(int j=i;j<=n;j++) cout<<la[j]<<" ";cout<<'\n';
//		cout<<'\n';
	}
	cout<<s<<'\n';
}
signed main(){
	
	freopen("migrate.in","r",stdin) , freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	
	cin>>tstid>>T;
	while(T--) solveA();
	
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


0 1
5 4
1 4 5 8 12

*/
/*1st----------------------------------------------------------------------------
#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int maxn=1e6*2+100;
int tstid,T;
int n,m,a[maxn],way[maxn],st[maxn],la[maxn];
void solveA(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int last=i;
		st[i]=0,la[i]=i;
		for(int j=i+1;j<=n;j++)
		{
			while(a[j]-a[last]>m) last++;
			if(j==last) 
			{
				la[j]=j;
				continue;
			}
			
			st[j]=st[last]+1;
			la[j]=last;
		}
		for(int j=i;j<=n;j++) cout<<st[j]<<" ";cout<<'\n';
		for(int j=i;j<=n;j++) cout<<la[j]<<" ";cout<<'\n';
		cout<<'\n';
	}
}
signed main(){
	
	//freopen("migrate.in","r",stdin) , freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	
	cin>>tstid>>T;
	while(T--) solveA();
	
	return 0;
}
*/


/*2nd----------------------------------------------------------------------------
#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int maxn=1e6*2+100;
int tstid,T;
int n,m,a[maxn],way[maxn],st[maxn],la[maxn],t1[maxn];
void solveA(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int last=1;
	st[1]=0,la[1]=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i]-a[last]>m) last++;
		if(i==last) 
		{
			la[i]=i;
			continue;
		}
		
		st[i]=st[last]+1;
		la[i]=last;
	}
//	for(int j=1;j<=n;j++) cout<<st[j]<<" ";cout<<'\n';
//	for(int j=1;j<=n;j++) cout<<la[j]<<" ";cout<<'\n';
//	cout<<'\n';
	for(int i=1;i<=n;i++)
	{
		if(la[i]+1==i) t1[la[i]]=i;
	}
	for(int l=1,r=1;r<=n;)
	{
		
	}
}
signed main(){
	
	//freopen("migrate.in","r",stdin) , freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	
	cin>>tstid>>T;
	while(T--) solveA();
	
	return 0;
}
*/
