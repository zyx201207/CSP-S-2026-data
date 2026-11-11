#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N],ch[N];
map<int,int> cnt;
bool f1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll cha=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cnt[a[i]]++;
		cha=a[2]-a[1];
		if(i>=2){
			if(a[i]-a[i-1]!=cha){
				f1=1;
			}
			ch[i]=a[i]-a[i-1];
		}
	}
	if(!f1){
		ll sum=0,sum1=cha,ans=1;
		while(1){
			if(sum+sum1<=m){
				sum=sum+sum1;
				sum1+=cha;
				ans++;
			}else{
				break;
			}
//			cout<<sum<<" ";
		}
		cout<<ans;
		return 0;
	}
	ll maxn=1,ans=1,sum=0,sum1=0;
	for(int i=2;i<=n;i++){
		ans=1,sum=0,sum1=0;
		for(int j=i;j>1;j--){
			sum1+=ch[j];
			if(sum+sum1>m){
				break;
			}
			sum+=sum1;
			ans++;
//			cout<<i<<" "<<sum1<<" "<<sum<<"\n";
		}
//		cout<<ans<<"-"<<i<<'\n';
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
