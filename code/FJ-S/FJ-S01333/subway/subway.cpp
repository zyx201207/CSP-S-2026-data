#include<bits/stdc++.h>
using namespace std;
struct s{
	int c,t;
}a[510][50010];
long long c,n,m,d,q,sum,w[500005],k[500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int p=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j].c>>a[i][j].t;
		}
	}
	for(int z=0;z<q;z++){
		int x,y;
		cin>>x>>y;
		int i=1,p=0;
		sum=0;
		while(1){
			for(int j=1;j<=k[i];j++){
				sum+=a[i][j].t;
				if(a[i][j].c==y){
					//cout<<"asfvaga"<<sum;
					p++;
					break;
					
				}
			}
			if(p!=0) break;
			i++;
		}
		sum+=w[x]+w[y];
		cout<<sum<<endl;
	}
	return 0;
}