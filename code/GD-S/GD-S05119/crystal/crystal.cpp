#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,s,a[100005],maa,mia=100000000000,ans=0;
	freopen("crystal1.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s);
		a[s]++;
		maa=max(maa,s);
		mia=min(mia,s);
	}
	//cout<<maa<<endl<<mia<<endl;
	for(int i=mia;i<=maa;i++){
		long long q=m,t=0;
		for(int j=i;j<=maa;j++){
			for(int k=a[j];k>0;k--){
				q-=(j-i);
				if(q<0) break;
				t++;
			}
			if(q<0) break;
		}
		ans=max(ans,t);
	}
	printf("%lld",ans);
	return 0;
}
