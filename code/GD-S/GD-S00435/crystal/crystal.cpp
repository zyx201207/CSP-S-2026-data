#include<bits/stdc++.h>
using namespace std;
long long n,m,mm,f[500010],l[500010],sum,ans,anns,mi=1e18,ma,A=1,B=1,x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>f[i];
        sum+=f[i];
        mi=min(f[i],mi);
        ma=max(ma,f[i]);
        if(f[i]!=i) A=0;
        if(i>2&&f[i]-f[i-1]!=x) B=0;
        if(i==2) x=f[2]-f[1];
    }
	if(A){
		int i=n/2;
		for(int j=1;j<=n;j++) l[j]=abs(f[j]-(long long)i);
		sort(l+1,l+1+n);
		ans=0;
		mm=m;
		for(int j=1;j<=n;j++){
//			if(i==4)cout<<l[j]<<' '<<j<<" "<<ans<<"
			if(mm-l[j]>=0){
				ans++,mm-=l[j];
			}
			else break;
		}
		cout<<ans;
    	return 0;
	}
	if(B){
		int i=n/2;
		for(int j=1;j<=n;j++) l[j]=abs(f[j]-(long long)i);
		sort(l+1,l+1+n);
		ans=0;
		mm=m;
		for(int j=1;j<=n;j++){
//			if(i==4)cout<<l[j]<<' '<<j<<" "<<ans<<"\n";
			if(mm-l[j]>=0){
				ans++,mm-=l[j];
			}
			else break;
		}
		cout<<ans;
		return 0;
	}
	for(int i=mi;i<=ma;i++){
		for(int j=1;j<=n;j++) l[j]=abs(f[j]-(long long)i);
		sort(l+1,l+1+n);
		ans=0;
		mm=m;
		for(int j=1;j<=n;j++){
//			if(i==4)cout<<l[j]<<' '<<j<<" "<<ans<<"\n";
			if(mm-l[j]>=0){
				ans++,mm-=l[j];
			}
			else break;
		}
		anns=max(ans,anns);
	}
    cout<<anns;
	return 0;
}
