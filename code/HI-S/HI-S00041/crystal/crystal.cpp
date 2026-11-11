#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
bool f=1;
vector<int> a,d;
vector<vector<int> > w;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	a.resize(n+1);
	d.resize(n+1);
	w.resize(n+1);
	a[0]=d[0]=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		if(d[i]!=d[i-1])f=0;
		w[i].resize(n-i+1);
		w[1][i]=0;
	}
	if(f){
		m/=d[1];
		ans=floor(sqrt(2*m+1)+0.5);
	}
	else
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				w[i][j]=w[i-1][j]+(d[j+i-1])*(i-1);
				if(w[i][j]<=m and i>=ans){
					ans=i;
				}
			}
		}
	printf("%d",ans);
	return 0;
}
