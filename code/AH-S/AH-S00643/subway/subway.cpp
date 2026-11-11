#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans,sum,w[500010];
int k[510],x[100010],y[100010];
int a[510][500010],t[510][500010];
bool b[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
		cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int i=0;i<q;i++)
		cin>>x[i]>>y[i];
	for(int l=0;l<q;l++){
		memset(b,0,n);
		b[x[l]]=1;
		sum=0;
		ans=w[x[l]-1]+w[y[l]-1];
		while(b[y[l]]!=1){
			for(int i=0;i<n;i++){
				for(int j=0;j<k[i];j++){
					if(b[a[i][j]]==1){
						for(int p=0;p<k[i];p++)
							b[a[i][p]]=1;
					}
				}
			}
			sum++;
		}
		ans+=t[0][0]*(sum+1)*2;
		cout<<ans<<endl;
	}
	return 0;
}
