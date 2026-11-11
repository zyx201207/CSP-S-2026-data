#include<bits/stdc++.h>
#define ll long long
const int MAXN=500005;
using namespace std;

ll n,m;
ll cf[MAXN];
ll a[MAXN],cnt[MAXN],ans[MAXN];
int mh=0;
ll mns,mus;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) cf[i]=a[i]-a[i-1];
	cf[1]=0;
	for(int i=1;i<=n;i++){
		cnt[i]=cnt[i-1]+cf[i]*(i-1);
		ans[i]=i;
		mh+=cf[i];
		ll small=1,temp=mh,tp=cnt[i];
		ll mns=0,mus=0;
		while(tp>m){
			tp-=temp;
			temp-=cf[small+1];
			small++;
			ans[i]--;
		}
	}
	int mm=-99;
	for(int i=1;i<=n;i++){
		if(ans[i]>mm) mm=ans[i];
	}
	cout<<mm;
	return 0;
}
