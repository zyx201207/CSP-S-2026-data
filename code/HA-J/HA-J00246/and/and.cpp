#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int cnt;
struct xixi{
	int id;
	int num;
	vector<int>q;
	int res;
}s[40];
bool cmp(xixi a,xixi b){
	if(a.res!=b.res){
		return a.res>b.res;
	}else{
		return a.id>b.id;
	}
}
bool cmp1(int a,int b){
	return a>b;
}
int maxn;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int j=a[i];
		cnt=0;
		maxn=INT_MIN;
		while(j>0){
			if((j&1)==1){
				s[cnt].num++;
				s[cnt].q.push_back(a[i]);
			}
			cnt++;
			maxn=max(maxn,cnt);
			j>>=1;
		}
	}
	for(int i=0;i<=maxn;i++){
		s[i].id=i;
	}
	for(int i=0;i<maxn;i++){
		s[i].res=s[i].num*pow(2,i);
	}
	sort(s,s+maxn,cmp);
	int ans=2147483647;
	for(int i=0;i<maxn;i++){
		sort(s[i].q.begin(),s[i].q.end(),cmp1);
		if(s[i].num>=m){
			int qqq=0;
			for(int qwq:s[i].q){
				ans=ans&qwq;
				qqq++;
				if(qqq>=m){
					break;
				}
			}
			cout<<ans<<endl;
			return 0;
		}else {
			for(int qwq:s[i].q){
				ans=ans&qwq;
			}
			m-=s[i].num;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
