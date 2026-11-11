#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
long long s[N];
int st[N];
vector<int> v[35];
int ans[N];

long long ma=-1; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i];
	}
	
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	
	ma=a[1];
	for(int i=2;i<=m;i++){
		ma=ma&a[i];
	}cout<<ma;
	/*for(int j=1;j<=n;j++){
		for(int i=31;i>=1;i--){
			int u=i-1;
			long long t=pow(2,u);
			
			if(a[j]>=t){
				a[j]-=t;
				v[i].push_back(j);
			}
		}
	}
	
	int ma=-1;
	for(int i=30;i>=1;i--){
		memset(st,0,sizeof(st));
		if(v[i].size()>=m){
			for(int j=0;j<v[i].size();j++){
				st[v[i][j]]++;
				cout<<v[i][j]<<" ";
			}
		}
		int tr=0;
		for(int i=1;i<=N;i++){
			if(st[i]>=m) tr++;
		}
		if(tr>=m){
			ma+=pow(2,i);
		}
	}cout<<ma;*/
	return 0;
}
