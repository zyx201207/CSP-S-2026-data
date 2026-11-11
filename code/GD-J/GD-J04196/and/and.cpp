#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=INT_MAX,a[200005],cnt;
struct node{
	int num,x;
};
bool use[200005];
vector<node>v(2000000,{0,0});
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<long long>());
	for(long long p=2;p<=pow(2,31);p*=2){
		v.assign(2000000,{0,0});
		for(int i=1;i<=n;i++){
			if(!use[i]){
				v[a[i]%p].num++;
				v[a[i]%p].x=a[i]%p;
			}
		}
		sort(v.begin(),v.end(),cmp);
		for(int i=1;i<=n;i++){
			if(!use[i]){
				if(a[i]%p==v[0].x){
					cnt++;
					ans&=a[i];
					use[i]=1;
					if(cnt==m){
						cout<<ans;
						return 0;
					}
				}
			}
		}
	}
}
