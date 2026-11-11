#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+2;
ll a[N],b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,P=1,ans=0;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>2)P=(P&(a[i]-a[i-1]==a[i-1]-a[i-2]));
	}
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<'\n';
	if(P)
	{
		for(int i=1;;i++){
			if(m<abs(i*(a[2]-a[1])))break;
			m-=abs(i*(a[2]-a[1]));
			ans++;
		}
		cout<<min(ans+1,n);
		return 0;
	}
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	int cnt,tinue;
	ll cntl;
	for(int i=2;;i++)
	{
		if(a[i]==a[i-1])continue;
		int q=m,t=0;
		for(int j=i;j>1;j--){
			if(q<b[j-1])break;
			q-=b[j-1];
			t++;
		}
		if(t<=i-1)
		{
			cnt=t;
			cntl=q;
			tinue=i;
			ans=cnt;
			break;
		}
	}
	for(int i=tinue+1;i<=n;i++)
	{
		if(a[i]==a[i-1]){
			cnt++;
			ans=max(ans,cnt);
			continue;
		}
		cnt++;
		cntl-=(cnt*b[i-1]);
		for(int j=i-cnt-1;j<i;j++){
			if(cntl<0){
				cnt--;
				cntl+=(a[i]-a[j]);
			}else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans+1;
	return 0;
}/*zhe di yi ti zhen de shi ren neng xie de ma?
gan jue zhe ci lian 100 fen dou mei you,
zhen de yao si le,
wo yi ji ku.*/
