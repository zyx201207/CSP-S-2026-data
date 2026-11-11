#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010],ans,one=1,ct=1,st[2000010];
struct node{
	long long l,r;
};
vector<node> s;
void kskbl(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	st[1]=1;
	for(int i=3;i<=n;i++){
		st[i]=1;
		if(a[i]-a[i-1]==d||(a[i]-a[i-1]<d&&a[i]-a[i-2]>d))ct++;
		else{
			if(ct>=2){
				s.push_back({i-ct,i-1});
			}
			ct=1;
		}
	}
	for(int i=0;i<s.size();i++){
		for(int j=s[i].l;j<=s[i].r;j++){
			st[j]=s[i].r-s[i].l+1;
		}
	}
	for(int i=4;i<=n;i++){
		if(a[i]-a[i-2]<=d&&a[i]-a[i-3]>d&&a[i-1]-a[i-3]<=d&&a[i-2]-a[i-3]<d){
			ans+=st[i-3]*st[i];
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)kskbl();
	return 0;
}
