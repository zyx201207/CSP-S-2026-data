#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int C,T,n,d,a[N],ls[N],nx[N],ls1[N],nx1[N],vl1[N],vl2[N],res[N],fsv[N],lsv[N];
vector<int> vc1[N],vc2[N];
inline void work(int op){
	for(int i=1;i<=n;i++)
		res[i]=0,fsv[i]=lsv[i]=0;
	for(int i=1;i<=n;i++)
		lsv[nx[i]]=i;
	for(int i=n;i>=1;i--)
		fsv[nx[i]]=i;
	for(int i=1;i<=n;i++){
		if(i!=ls[i]&&nx[ls[i]]==i) res[i]=res[ls[i]]+1;
		else res[i]=1;
		int ps=max(ls[i]+1,fsv[i]),ps2=min(i-1,lsv[i]);
		res[i]+=max(0ll,ps2-ps+1);
		if(op==1) vl1[i]=res[i];
		else vl2[n-i+1]=res[i];
	}
}
inline void Main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int t=n;
	for(int i=n;i>=1;i--){
		while(a[t]-a[i]>d)
			t--;
		nx[i]=t;
	}
	t=1;
	for(int i=1;i<=n;i++){
		while(a[i]-a[t]>d)
			t++;
		ls[i]=t;
	}
	for(int i=1;i<=n;i++)
		ls1[i]=ls[i],nx1[i]=nx[i];
	for(int i=1;i<=n;i++)
		vc1[ls[i]].push_back(i),vc2[nx[i]].push_back(i);
	work(1);
	for(int i=1;i<=n;i++)
		ls[n-i+1]=n-nx1[i]+1,nx[n-i+1]=n-ls1[i]+1;
	work(2);
	int ans=0;
	for(int i=1;i<n;i++){
		int rv=0,lv=0;
		for(auto &j:vc1[i])
			if(j>i+1){
				if(nx1[i+1]==j) rv+=vl2[j];
				else rv++;
			}
		for(auto &j:vc2[i+1])
			if(j<i){
				if(ls1[i]==j) lv+=vl1[j];
				else lv++;
			}
		ans+=rv*lv;
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)
		vl1[i]=vl2[i]=0,vc1[i].clear(),vc2[i].clear();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--)
		Main();
	return 0;
}
