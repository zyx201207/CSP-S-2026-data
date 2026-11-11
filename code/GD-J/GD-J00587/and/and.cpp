#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*1e5+5;
long long n,m,a[MAXN],sum[MAXN],ans,t;
bool b[MAXN];
vector<int> s[30];
void f(int x){
	for(int i=0;i<s[x].size();i++){
		int y=s[x][i];
		if(b[y]==1)
			continue;
		b[y]=1;
		for(int j=30;j>=0;j--){
			if((a[y]&(1<<j))==0){
				sum[j]--;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	t=n-m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			if((a[i]&(1<<j))==0){
				sum[j]++;
				s[j].push_back(i);
			}
		}
	}
	memset(b,0,sizeof(b));
	for(int i=30;i>=0;i--){
		if(t>=sum[i]){
			t-=sum[i];
			ans+=(1<<i);
			f(i);
		}
	}
	cout<<ans;
	return 0;
}

