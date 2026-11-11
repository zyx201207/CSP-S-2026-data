#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[5000005],mi[5000005],cnt[5000005],ck,l,lst[5000005],ans;
struct il{
	long long v,de;
}tmp,nw;
queue<il> s;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		ck=l=1;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			mi[i]=cnt[i]=0;
		}
		//cout<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cnt[j]=lst[j]=0;
			} 
			while(!s.empty()) s.pop();
			tmp.v=i;tmp.de=0;
			s.push(tmp);
			while(!s.empty()){
				nw=s.front();
				if(lst[nw.v]==0) lst[nw.v]=nw.de;
				//if(i==2)cout<<nw.v<<' '<<nw.de<<endl;
				if(nw.de==lst[nw.v]) cnt[nw.v]++;
				if(nw.de-lst[nw.v]>1){
					s.pop();
					continue;
				}
				for(int j=nw.v+1;j<=n;j++){
					//cout<<d<<' '<<a[i]<<' '<<a[nw.v]<<endl;
					tmp.v=j;tmp.de=nw.de+1;
					if(a[j]-a[nw.v]<=d) s.push(tmp);
				}
				//cout<<endl;
				s.pop();
			}
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2) {
					ans++;
					//cout<<i<<' '<<j<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
