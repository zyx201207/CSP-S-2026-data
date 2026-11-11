#include <bits/stdc++.h>
using namespace std;
long long n,m,k,sum;
const int N=5e5+10,M=500;
long long w[N],zh[N],a[M][M],c,d,q,t[M][M],r,e,b,v;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int l=0;l<k;l++){
					if(a[i][l]==a[j][l]) zh[l]=t[i][l]+t[j][l];
			}
		}
	}
	int u=0;
	for(int i=0;i<k;i++){
		if(zh[i]>=u){
			u=zh[i];
		}
	}
	for(int i=0;i<k;i++){
		if(zh[i]==u) u=i-1;
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		for(int j=0;j<n;j++){
			for(int l=0;l<k;l++){
				if(a[j][l]==x) r++,b=i;
				if(a[j][l]==y) e++,v=i;
			}
			if(r==1&&e==1){
				sum+=w[x-1]+t[j][x-1]+t[j][y-1]+w[y-1];
			cout<<sum;
				cout<<sum;
				break;
			}
		}
		if(r!=1&&e!=1){
			sum+=w[x-1]+t[b][x-1]+zh[u]+w[y-1]+t[v][y-1];
		
		}
	}
}
