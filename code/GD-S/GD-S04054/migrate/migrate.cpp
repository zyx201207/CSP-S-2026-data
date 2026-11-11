#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
const int INF=0x3f3f3f3f;
int c,t,n,d,x[N],ans,k,minl;
void fy(int s,int e,int l){
	if(s==e){
		if(minl>l){
			k=1;
			minl=l;
		}else k++;
		return;
	}
	for(int i=s+1;i<=e;i++){
		if(x[i]-x[s]<=d){
			fy(i,e,l+1);
		}
		else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int cha;
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			//cin>>x[i];
			if(c==11||c==12){
				if(i==2){
					cha=x[2]-x[1];
				}
			}
		}for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				k=0;
				minl=INF;
				fy(i,j,0);
				if(k==2)ans++;
			}
		}cout<<ans<<endl;
	}
	return 0;
}

