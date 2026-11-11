#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=505;
long long le,n,m,d,q,k[M],c[N][N],a[M][N],t[M][N],w[M],sb[M],bj[M];
void find(long long now){
	for(int i=1;i<=n;i++){
		if(i==now){
			continue;
		}
		if(c[now][i]!=0){
			if(sb[i]==0||bj[i]==1)
			sb[i]=sb[now]+c[now][i];
			else
			sb[i]=min(sb[now]+c[now][i],sb[i]);
			c[now][i]=0;
			find(i);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>le>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long sb1,sb2;
			cin>>sb1>>sb2;
			a[i][sb1]=sb2;
		}
	}
	long long js=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(a[i][k]!=0&&a[j][k]!=0){
					if(c[i][j]==0){
						c[i][j]=a[i][k]+a[j][k];
					}
					
					else
					c[i][j]=min(c[i][j],a[i][k]+a[j][k]);
				}
			}
		}
	}
	for(int i=2;i<=n;i++){
		sb[i]=c[1][i];
	}
	find(1);
	while(q--){
		long long s1,s2,a1[M],a2[M],js1=0,js2=0,ans=1000000000;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			if(a[i][s1]!=0){
				js1++;
				a1[js1]=i;
			}
			if(a[i][s2]!=0){
				js2++;
				a2[js2]=i;
			}
		}
		for(int i=1;i<=js1;i++){
			for(int j=1;j<=js2;j++){
				if(a1[i]==a2[j]){
					ans=min(a[a1[i]][s1]+a[a2[j]][s2],ans);	
				}
				if(abs(sb[a1[i]]-sb[a2[j]])!=0)
				ans=min(abs(sb[a1[i]]-sb[a2[j]])+a[a1[i]][s1]+a[a2[j]][s2],ans);
				
			}
		}
		cout<<ans+w[s1]+w[s2]<<endl;
		
	}
	return 0;
}
