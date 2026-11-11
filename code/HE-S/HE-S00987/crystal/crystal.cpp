#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int n;
long long m,a[MAXN],c[MAXN],ct[MAXN],maxx;
bool cmp(int x,int y){
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	a[0]=0;
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		for(int j=1;j<=i-1;j++) c[j]=a[i]-a[j];
		int m1=m;
		int u=i-1;
		while(m1>=0&&u>0){
			if(c[u]==0){
				ct[i]++;
				u--;
			}
			else{
				m1--;
				c[u]--;
				
			}
		}
		if(ct[i]>0) ct[i]++;
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,ct[i]);
	}
	cout<<maxx<<'\n';
	return 0;
}

