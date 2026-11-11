#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,b[200005][32],er,tt,maxx,t[200005],ll,kk,h[200005],ans;
struct gf{
	int zhi,xia;
}a[200005]; 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i].zhi);
		a[i].xia=i;
		er=a[i].zhi,tt=0;
		while(er>0){
			b[i][tt]=er%2;
			er/=2;
			tt++;
		}
		maxx=max(maxx,tt-1);
	}
	/*
	cout<<endl;
	for(int i = 1;i<=n;i++){
		for(int j = maxx;j>=0;j--){
			cout<<b[i][j];
		}
		cout<<endl;
	}
	cout<<"-----------------------"<<endl;
	*/
	for(int i=1;i<=n;i++){
		t[i]=i;
	}
	ll=n;
	for(int i=maxx;i>=0;i--){
		kk=0;
		for(int j = 1;j<=ll;j++){
			if(b[t[j]][i]==1){
				kk++;
				h[kk]=t[j];
			}
		} 
		if(kk>=m){
			//memset(t,0,sizeof(t));
			for(int j=1;j<=kk;j++){
				t[j]=h[j];
			}
			//memset(h,0,sizeof(h));
			ans+=(1<<i);
			ll=kk;
		}
		/*
		cout<<"i:"<<i<<" kk:"<<kk<<" 2^i:"<<(1<<i)<<" ans:"<<ans<<endl;
		for(int j=1;j<=kk;j++){
			cout<<t[j]<<" ";
		}
		cout<<endl;
		*/
	}
	printf("%lld",ans);
	return 0;
}
