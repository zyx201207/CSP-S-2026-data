#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,sz,p,ans,anst,a[500005];
bool bj[500005];
main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=31;i>=0;i--){
		if(p==0){
			//º”»À 
			for(int j=1;j<=n;j++){
				if(bj[j]==1) continue;
				if((a[j]>>i)%2==1){
					sz++;
					bj[j]=1;
				}
			}
		}else{
			//Ãﬂ»À
			for(int j=1;j<=n;j++){
				if(bj[j]==0) continue;
				if((a[j]>>i)%2==0){
					sz--;
					bj[j]=0;
				}
			}
		}
		if(sz>=m){
			ans=-1;
			for(int j=1;j<=n;j++){
//				cout<<bj[j]<<" ";
				if(bj[j]==1){
					if(ans==-1) ans=a[j];
					else ans&=a[j];
				} 
			}
			anst=max(anst,ans);
//			cout<<"\n";
//			cout<<sz<<" "<<ans<<"\n";
		}
		if(sz==m){
			break;
		}else if(sz<m){
			for(int j=1;j<=n;j++) bj[j]=0;
			sz=0;
			p=0;
		}else{
			p=1;
		}
	}
	cout<<anst;
	return 0;
} 
