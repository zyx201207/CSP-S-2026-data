//GZ-00400 毕节梁才学校 张静峰 
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int c,t;
int n,m;
const int N=2e6+10;
LL a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	//if(c==12||c==22){
		while(t--){
			scanf("%d%d",&n,&m);
			
			for(int i=1;i<=n;i++){
				scanf("%d",&a[i]);
			}
			if(a[2]-a[1]>=m){
				printf("0\n");
				continue;
			}
			LL c=a[2]-a[1];
			cout<<n<<"   "<<m<<"    "<<c<<endl;
			//等差数列中 
			int t=c/m;
			
		}
	//}
	
	
	return 0;
}
