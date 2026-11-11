#include<bits/stdc++.h>
using namespace std;
long long n,sum,sum2,w,n1,n2,h1,h2,ans,fi,fj;
struct dn
{
	long long s;
	char ch;
}a[200005],lt[200005],rt[200005];
int main()
{
	cin.tie(0),ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++) cin>>a[i].s>>a[i].ch,sum+=a[i].s;
	sum/=2;
	while(sum2+a[w].s<=sum) lt[w]=a[w],sum2+=a[w].s,w++;
	if(sum2<sum) lt[w]={sum-sum2,a[w].ch},w++;
	n1=w;
	w=0,sum2=0;
	while(sum2+a[n-w-1].s<=sum) rt[w]=a[n-w-1],sum2+=a[n-w-1].s,w++;
	if(sum2<sum) rt[w]={sum-sum2,a[n-w-1].ch},w++;
	n2=w;
//	for(long long i=0;i<n1;i++) cout<<lt[i].s<<" "<<lt[i].ch<<"\n";
//	cout<<"\n";
//	for(long long i=0;i<n2;i++) cout<<rt[i].s<<" "<<rt[i].ch<<"\n";
//	cout<<"\n";
	h1=lt[0].s,h2=rt[0].s,ans+=min(h1,h2)*(lt[0].ch!=rt[0].ch);
	fi=1,fj=1;
	while(fi<n1&&fj<n2)
	{
		if(h1<=h2) ans+=min(lt[fi].s,h2-h1)*(lt[fi].ch!=rt[fj-1].ch),h1+=lt[fi].s,fi++;
		else ans+=min(rt[fj].s,h1-h2)*(lt[fi-1].ch!=rt[fj].ch),h2+=rt[fj].s,fj++;
	}
	while(fi<n1) ans+=min(lt[fi].s,h2-h1)*(lt[fi].ch!=rt[fj-1].ch),h1+=lt[fi].s,fi++;
	while(fj<n2) ans+=min(rt[fj].s,h1-h2)*(lt[fi-1].ch!=rt[fj].ch),h2+=rt[fj].s,fj++;
	cout<<ans;
	return 0;
}
