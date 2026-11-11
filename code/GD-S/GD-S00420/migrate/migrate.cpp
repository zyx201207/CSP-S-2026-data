#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000006],mn[2000006],mx[2000006];
int dpl[2000006],dpr[2000006];
inline int sum(int l,int r){
	if(l>r) return 0;
	return r-l+1;
}
void subtask_diff(){
	int len=1;
	while(len<n&&a[len+1]-a[1]<=d) len++;
	if(len<3){
		cout<<"0\n";
		return;
	}
	cout<<max(0ll,n-(len*2-3))<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
//	t=1;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i],dpl[i]=dpr[i]=1;
		if(c==11||c==12){
			subtask_diff();
			continue;
		}
//		for(int i=2;i<=n;i++) cout<<a[i]-a[i-1]<<' ';
//		cout<<'\n';
		for(int i=1,j=1;i<=n;i++){
			while(a[i]-a[j]>d) j++;
			mn[i]=j;
		}
		for(int i=n,j=n;i>0;i--){
			while(a[j]-a[i]>d) j--;
			mx[i]=j;
		}
		for(int i=1,j=1;i<=n;i++){
			while(j<=n+1&&a[j]-a[i]<=d) j++;
			dpl[j-1]+=dpl[i];
//			cout<<i<<' '<<dpl[i]<<'\n';
		}
		for(int i=n,j=n;i>0;i--){
			while(j>=0&&a[i]-a[j]<=d) j--;
			dpr[j+1]+=dpr[i];
//			cout<<i<<" "<<dpr[i]<<'\n';
		}
		int ans=0;
		for(int i=3;i<n;i++){
			int llef,lrig,rlef,rrig;
			llef=mn[i],lrig=min(mn[i+1],i-1)-1;
			rlef=max(mx[i-2],i)+1,rrig=mx[i-1];
			if(llef>lrig||rlef>rrig) continue;
			if(c==13||c==14) ans+=(lrig-llef+1)*(rrig-rlef+1);
			else ans+=(dpl[llef]+sum(llef+1,lrig))*(sum(rlef,rrig-1)+dpr[rrig]);
//			cout<<i<<" "<<llef<<' '<<lrig<<' '<<rlef<<' '<<rrig<<' '<<(dpl[llef]+sum(llef+1,lrig))<<' '<<(sum(rlef,rrig-1)+dpr[rrig])<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}//Good luck!
