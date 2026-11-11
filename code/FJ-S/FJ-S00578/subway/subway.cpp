#include<bits/stdc++.h>
using namespace std;
int w[500003],K[510],a[1003][1003],t[1003][1003],rx[100005],ry[100005];
long long ans=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>rx[i]>>ry[i];
	}
	ans+=w[rx[0]-1]+w[ry[0]-1];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==ry[0])ans+=t[i][j];
		}
	}
	cout<<ans<<endl;
	ans+=w[rx[1]-1]+w[ry[1]-1];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==ry[1])ans+=t[i][j];
		}
	}
	cout<<ans;
	return 0;
}

