#include<bits/stdc++.h>
using namespace std;
int w[100005];
int a[100005][100005];
int t[100005][100005];
int x[100005],y[100005];
int c,n,m,d,q,ans=0,cnt,s,l;
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		cout<<"hello";
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		ans=0;
		ans+=w[x[i]];
		for(int j=1;j<=n;j++){
			for(int h=1;h<=m;h++){
				if(a[j][h]==x[q]){
					ans+=t[j][h];
					cnt = 1;
			   }
			   if(a[j][h]==y[q]&cnt==1){
					ans+=t[j][h];
					ans+=w[a[j][h]];
					break;
			   }else if(a[j][h]==y[q]){
			   		l=h;
			   }
			}
		}
		cout<<ans;
	}
	cout<<ans;
	return 0;
}

