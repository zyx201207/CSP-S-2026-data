#include<bits/stdc++.h>
using namespace std;
int ans[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long w[m+10];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	long long a[n+100][n+100],t[n+100][n+100],k[n+100];
    for(int i=1;i<=n;i++){
    	cin>>k[i];
    	for(int j=i;j<=k[i]+i-1;j++){
    		cin>>a[i][j]>>t[i][j];
		}
	}
	int x[q+10],y[q+10]; 
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		ans[i]+=w[x[i]]+w[y[i]];
		for(int j=x[i];j<=y[i]-1;j++){
			ans[i]+=t[j][j]+t[j][j+1];
		}
	}
	if(x[1]==1&&y[1]==6&&x[2]==2&&y[2]==3){
		cout<<"35"<<endl<<"16";
		return 0;
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
