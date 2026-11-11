#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll n,m,k,ans=0;
ll a[500005];
ll b[500005];
//int t[1000000000005];
map <ll,int> t;

//bool cmp(int x,int y){
//	return abs(x-k)<abs(y-k);
//}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	cin>>n>>m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
	scanf("%lld",&a[i]);
		t[a[i]+1e12]++;
		if(t[a[i]+1e12]==1) b[++k]=a[i];
	}
	sort(b+1,b+k+1);
	for(int i=1;i<=k;i++){
		ll nk=m;
		ll sum=t[b[i]+1e12];
		for(int j=i-1;j>=1;j--){
			if(nk>=t[b[j]+1e12]*(b[i]-b[j])){
				nk-=t[b[j]+1e12]*(b[i]-b[j]);
				sum+=t[b[j]+1e12];
//				cout<<'+'<<t[b[j]+1e12];
			}else{
				sum+=nk/(b[i]-b[j]);
//				cout<<'+'<<nk/(b[i]-b[j]);
				nk-=nk/(b[i]-b[j])*(b[i]-b[j]);
				break;
			}
		}
//		cout<<'\n';
//		cout<<sum<<'\n';
		ans=max(ans,sum);
	}
	printf("%lld",ans);
}
