#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,sum=0;
int w[500010];
int x[100010],y[100010];
int ii[505];
long long a[1005],t[1005],top1[10005];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ii[i];
	for(int j=1;j<=ii[i];j++){
		cin>>a[j];
	}	
	for(int k=1;k<=ii[i];k++){
		cin>>t[k];
		sum[top1]+=t[k];
		top1++;
	}}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=top1-1;i++){
		cout<<sum[i]<<endl;
	}
	return 0;
}
