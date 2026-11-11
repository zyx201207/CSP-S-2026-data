#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005][35],d[35],flag[200005],t[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=0,r=1;
		while(r<=a[i]){
			d[k+1]+=(a[i]>>k)&1;
			b[i][k+1]=(a[i]>>k)&1;
			k++;
			r*=2;
		}
	}
	for(int i=30;i>=1;i--){
		if(d[i]>=m){
			t[i]=1;
			for(int j=1;j<=n;j++){
				if(b[j][i]==0&&!flag[j]){
					flag[j]=1;
					for(int k=i;k>=1;k--){
						if(b[j][k]){
							d[k]--;
						}
					}
				}
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=30;i++){
		if(t[i]){
			ans+=t[i]<<(i-1);
		}
	}
	cout<<ans;
	return 0;
}
