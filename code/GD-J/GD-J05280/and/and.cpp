#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
struct stu{
	string s;
	ll x;
	ll gaowei;
}a[100005];
ll sum[100005];
string zf(ll t){
	string s1;
	while(t){
		s1+=t%2+'0';
		t/=2;
	}
	reverse(s1.begin(),s1.end());
	return s1;
	
}
bool cmp(stu a,stu b){
	return a.s.size()>b.s.size();
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n;i++){
		cin>>a[i].x;
		a[i].s=zf(a[i].x);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].s.size();j++){
			sum[j]+=a[i].s[j]-'0';
		}
	}
	sort(a+1,a+1+n,cmp);
	ll f=0;
	ll maxx=a[1].s.size();
	string w[10005],wt[10005],wgw[10000];
	ll ans=0,kz=0;
	for(int i=0;i<maxx;i++){
		if(sum[i]<m){
			continue;
		}
		
			ans+=pow(2,(maxx-1)-i);
			for(int j=1;j<=n;j++){
				if(a[j].s[maxx]==1){
					w[++kz]=a[j].s;
					wt[kz]=a[j].x;
				}	
			}
		}
		
	

	
	return 0;
}
