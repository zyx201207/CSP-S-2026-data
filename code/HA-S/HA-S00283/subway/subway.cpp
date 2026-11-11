#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[505][N]={0},t[505][N]={0};
int w[N],k[N],x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,num=0,sum,cnt=0,o=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		num+=w[x[i]];
		num+=w[y[i]];
		for(int h=1;h<=n;h++){
			for(int j=1;j<=k[h];j++){
				if(a[h][j]==x[i]||o==0){
					sum=h;
					o++;
					h=1;j=1;
				}
				if(a[h][j]==y[i]||o==1){
					for(int g=1;g<=k[h];g++){
						for(int l=1;l<=k[sum];l++){
							if(a[h][g]==a[sum][l]&&cnt==0){
								num+=t[h][g];
								num+=t[sum][l];
								num+=a[h][j];
								cnt++;
							}
						}
					}
				}
			}
		}
		cout<<num<<endl;
		num=0;
		o=1;
		cnt=0;
	}
	return 0;
}
