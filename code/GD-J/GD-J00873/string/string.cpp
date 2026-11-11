#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define Int int
using namespace std;
const int N=2e5+5,M=1e2+5;
const int INF=0x3f3f3f3f,MOD=1e9+7;
int n,a[N],sum;
char c[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(Int i=1;i<=n;i++)
		cin>>a[i]>>c[i],sum+=a[i];
	int mid=(sum+1)/2,res=0;
	vector<pair<int,char>>l,r;
	Int pos=0;
	for(Int i=1;i<=n;i++){
		res+=a[i];
		if(res<mid)l.push_back({a[i],c[i]});
		else{
			r.push_back({res-mid,c[i]});
			res-=a[i];
			l.push_back({mid-res,c[i]}); 
			pos = i+1;
			break;
		}
	}
	for(Int i=pos;i<=n;i++)
		r.push_back({a[i],c[i]});
	reverse(r.begin(),r.end());
	Int li=0,ri=0;
	int ans=0,resl=l[li].first,resr=r[ri].first;
	res = 0;
	while(li<l.size()&&ri<r.size()){
		if(resl<resr){
			if(l[li].second!=r[ri].second)ans+=resl;
			resr-=resl,resl = l[++li].first;
		}else{
			if(l[li].second!=r[ri].second)ans+=resr;
			resl-=resr,resr = r[++ri].first;
			if(!resl)resl = l[++li].first;
		}
	}
	cout<<ans<<endl; 
	return 0;
}

