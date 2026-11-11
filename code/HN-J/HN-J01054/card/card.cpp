#include<bits/stdc++.h>
using namespace std;
int n,m,f[500005],a[500005],s[300005],p[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],p[i]=a[i];
	for(int i=1;i<=n;i++){
		for(int z=1;z<i;z++) p[z]=0;
		for(int j=i;j<=n;j++){
			for(int x=i;x<j;x++){
				if(p[x]==p[j]){
					for(int y=x;y<j;y++) p[y]=0;
					break;
				}
			}
		}
		for(int x=1;x<=n;x++){
			if(f[p[x]]==0){
				s[p[x]]++;
				f[p[x]]=1;
			}
		}
		for(int z=1;z<=n;z++){
			p[z]=a[z];
			f[z]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
