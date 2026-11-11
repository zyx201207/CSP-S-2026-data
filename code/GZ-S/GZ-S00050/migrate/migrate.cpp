//GZ-S00050，阮辰允，贵阳市白云区华师一学校 
#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,x[2000001],n,d;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
    	cin>>n>>d;
    	if(n==1){
    		cout<<0<<'\n';
    	    continue;
		}
    	for(int j=1;j<=n;j++){
    		cin>>x[j];
		}
    	if(c==11||c==12){
    		int k=d/(x[2]-x[1]);
    		cout<<n-2*k+1<<'\n';
    		continue;
		}
		int ans=0;
		vector<int> to(n+1),bk(n+1);
		for(int j=1;j<=n;j++){
			int l=j,r=n,res;
			while(l<=r){
				int mid=(l+r)>>1ll;
				if(x[mid]-x[j]<=d){
					res=mid;
					l=mid+1;
				}
				else{
					r=mid-1;
				}
			}
			to[j]=res;
			l=1,r=j;
			while(l<=r){
				int mid=(l+r)>>1ll;
				if(x[j]-x[mid]<=d){
					res=mid;
					r=mid-1;
				}
				else{
					l=mid+1;
				}
			}
			bk[j]=res;
		}
		for(int j=1;j<=n-3;j++){
			for(int k=j+3;k<=n;k++){
				bool fl=1;
				vector<int> jk,kj;
				for(int l=j;l<k;l=to[l]){
					jk.push_back(l);
					if(to[l]>=k){
						jk.push_back(k);
					}
					else if(to[l]==l){
						fl=0;
						break;
					}
				}
				if(!fl){
					continue;
				}
				int ps=jk.size();
				for(int l=k;l>j;l=bk[l]){
					kj.push_back(l);
					if(bk[l]<=j){
						kj.push_back(j);
					}
				}
				int sum=0;
				for(int l=0;l<ps;l++){
					sum+=jk[l]-kj[ps-1-l];
				}
				if(sum==1){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
    return 0;
}
