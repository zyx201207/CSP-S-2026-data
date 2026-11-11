#include<bits/stdc++.h>
using namespace std;
long long n,l,l1,l2,bt,ct,ans;
pair<long long,char> a[200005],b[200005],c[200005];
pair<long long,int> d[400010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second,l+=a[i].first;
	for(int i=1;i<=n&&l1<l/2;l1+=a[i].first,i++) b[i]={l1+1,a[i].second},bt=i;
	for(int i=n;i>=1&&l2<l/2;l2+=a[i].first,i--) c[n-i+1]={l2+1,a[i].second},ct=n-i+1;
	b[bt+1]={l/2+1,0};
	c[ct+1]={l/2+1,0};
	for(int i=1;i<=bt+1;i++) d[i]={b[i].first,i};
	for(int i=1;i<=ct+1;i++) d[i+bt+1]={c[i].first,i+bt+1};
	sort(d+1,d+bt+ct+3);
	char bn,cn;
	for(int i=1;i<=bt+ct+2;i++){
		if(d[i].second>bt+1) cn=c[d[i].second-bt-1].second;
		else bn=b[d[i].second].second;
		if(d[i].first==d[i+1].first) continue;
		ans+=d[i].first;
		if(i!=bt+ct+2){
			if(bn!=cn) ans-=d[i].first;
			else ans-=d[i+1].first;
		}
	}
	cout<<ans-1;
	return 0;
}
