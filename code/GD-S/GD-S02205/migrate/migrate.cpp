#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,a[N],n,k,nxt[N],pre[N],cnt1[N],cnt2[N]; 
bool ck(int a,int b){
	int res=0,x=a,idx=1;
	cnt1[1]=cnt2[1]=a;
//	cout<<a<<' '<<b<<'\n';
	while(x<b){
		if(x==nxt[x])return 0;
		cnt1[++idx]=nxt[x];
		x=nxt[x];
	//	cout<<"AAA"<<idx<<' '<<x;
	}
	cnt2[idx]=cnt1[idx]=b;
	int nidx=idx;
	x=b;
	while(x>a){
		cnt2[--nidx]=pre[x];
	//	cout<<nidx<<' '<<pre[x]<<'\n';
		x=pre[x];
	}cnt1[1]=cnt2[1]=a;cnt2[idx]=cnt1[idx]=b;
//	cout<<a<<' '<<b<<'\n';
	for(int i=1;i<=idx;i++){
	//	cout<<i<<' '<<cnt1[i]<<' '<<cnt2[i]<<'\n';
		res+=abs(cnt2[i]-cnt1[i]);
	}
//	cout<<"RES"<<res<<'\n';
	return res==1;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		if(c>8){
			cout<<0<<'\n';
			continue;
		} 
		int ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];a[i]+=1e18;
		}
		int j=1;
		a[n+1]=2e18,a[0]=0;
		nxt[n]=n;
		for(int i=1;i<=n;i++){
			while(a[j+1]-a[i]<=k&&j<n)j++;
			nxt[i]=max(j,i);
			j=max(j,i);
		//	cout<<nxt[i]<<endl;
		}
	//	cout<<'\n';
		j=n;
		for(int i=n;i>=1;i--){
			while(a[i]-a[j-1]<=k)j--;
			pre[i]=min(j,i);
			j=min(j,i);
		//	cout<<pre[i]<<endl;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans+=ck(i,j);
			}
		}
		cout<<ans<<'\n';
	}
   return 0;
}


