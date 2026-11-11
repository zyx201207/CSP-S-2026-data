#include<bits/stdc++.h>
using namespace std;
bool a[100000];
int wz[1000][1000],x=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int o=1;o<=t;o++){
		long long zb[100000],fc[10000],d;
		int n;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>zb[i];
			fc[i]=zb[i]-zb[i-1];
			a[zb[i]]=1;
		}
		vector<int> aa[3];
		x=0;
		for(int i=3;i<=n;i++){
			for(int j=i-1;zb[j]>=zb[i]-d&&j>0;j--){
				for(int l=j-1;zb[l]>=zb[j]-d&&l>0;l--){
					wz[i][l]+=1;
				}
			}
			for(int j=i;zb[j]>zb[i]-d-d&&j>0;j--){
				if(wz[i][j]==2&&zb[i]-zb[j]>d){
//					cout<<i<<' '<<j<<endl;
					x+=1;	
				}
				wz[i][j]=0;
			}
//			cout<<x<<endl;
		}
		cout<<x<<endl;
	} 
	return 0;
} 
