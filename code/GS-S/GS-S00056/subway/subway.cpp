#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long w[N],a[505][5],t[505][5],k[N],x[N],y[N];
long long c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		cin>>a[i][1]>>t[i][1]>>a[i][2]>>t[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	//if(c==7 || c==8){
		for(int i=1;i<=n;i++){
			bool flag=0;
			for(int j=1;j<=n;j++){
				if(a[i][1]>a[j][1]){
					swap(a[i][1],a[j][1]);
					swap(a[i][2],a[j][2]);
					swap(t[i][1],t[j][1]);
					swap(t[i][2],t[j][2]);
					flag=1;
				}
			}
			if(flag==0){
				break;
			}
		}
		//cout<<"mj";
	//}
	
	if(c>=7 && c<=11){
		for(int i=1;i<=q;i++){
			long long ans=0;
			if(x[i]<y[i]){
				for(int j=x[i];j<y[i];j++){
					ans+=t[j][1]+t[j][2];
					//ans+=w[x[i]]+w[y[i]];
				}
				//cout<<x[i]<<' '<<y[i]<<'\n';
			}
			if(x[i]>y[i]){
				for(int j=y[i];j<x[i];j++){
					ans+=t[j][1]+t[j][2];
					//ans+=w[x[i]]+w[y[i]];
				}
				//cout<<x[i]<<' '<<y[i]<<'\n';
			}
			//ans-=t[x[i]][1];
			ans+=w[x[i]]+w[y[i]];
			cout<<ans<<endl;
		}
	}
	else{
		for(int i=1;i<=q;i++){
			cout<<0<<endl;
		}
	}
	//cout<<111;
	return 0;
} //25pts
//Oct31==Dec25?
/*rp++*/
