#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N];
bool used[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			long long cnt=m;
			int num=0,l=i,r=i;
			if(i==1){
				while(r<=n){
					if(cnt>=a[r]-a[i]) cnt-=a[r]-a[i],r++,num++;
					else break;
				}
			}
			else if(i==n){
				while(l>=1){
					if(cnt>=a[i]-a[l]) cnt-=a[i]-a[l],l--,num++;
					else break;
				}
			}
			else{
				for(int i=1;i<=n;i++) used[N]=false;
				while(l>=1&&r<=n){
					if(cnt>=min(a[i]-a[l],a[r]-a[i])){
						if(a[i]-a[l]<=a[r]-a[i]) cnt-=a[i]-a[l],l--,num++;
						else cnt-=a[r]-a[i],r++,num++;
					}
					else break;
				}
			}
			ans=max(ans,num);
		}
		cout<<ans;
	return 0;
}
