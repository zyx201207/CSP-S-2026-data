#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[5000005],s[5000005],p[5000005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(s,0,sizeof s);
		int k=1;
		s[k]=a[i];
		for(int j=i+1;j<=n;j++){
			bool f=1;
			for(int l=1;l<=k;l++){
				if(a[j]==s[l]){
					for(int r=l+1;r<=k;r++){
						s[r]=0;
					}
					f=0;
					break;
				}
			}
			if(f==1)s[++k]=a[j];
		}
		for(int j=1;j<=k;j++){
			p[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
