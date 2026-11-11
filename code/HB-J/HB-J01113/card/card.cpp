#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005],ans,cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i]=0;
		}
		ans=0;
		for(int j=i;j<=n;j++){
			ans++;
			cnt=0;
			for(int k=1;k<ans;k++){
				if(a[j]==c[k]){
					for(int ii=k;ii<ans;ii++){
						c[ii]=0;
						cnt++;
					}
					break;
				}
			}
			ans-=cnt;
			c[ans]=a[j];
		}
		for(int j=1;j<=ans;j++){
			b[c[j]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
