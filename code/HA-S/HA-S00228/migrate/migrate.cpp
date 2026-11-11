#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,fs[2000005],dy[2000005],jb[2000005],zx,zxf,zsb,ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>dy[j];
		}
		for(int q=1;q<=n;q++){
			for(int j=q;j<=n;j++){
				jb[j]=0,fs[j]=0;
				if(j==q){
					fs[q]=1;
				}
				if(dy[j]-d>=dy[q]){
					zx=lower_bound(dy+q,dy+j,dy[j]-d)-dy;
				}
				else{
					zx=q;
				}
				zsb=jb[zx];
//				cout<<zx<<" "<<zsb<<" "<<endl;
				for(int k=zx;k<j&&jb[k]==zsb;k++){
					fs[j]+=fs[k];
					jb[j]=zsb+1;
				}
				if(fs[j]==2){
					ans++;
				}
				if(fs[j]==0||fs[j]==3){
					break;
				}
			}
//			for(int j=q;j<=n;j++){
//				cout<<fs[j]<<" ";
//			}
//			cout<<endl;
//			for(int j=q;j<=n;j++){
//				cout<<jb[j]<<" ";
//			}
//			cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
