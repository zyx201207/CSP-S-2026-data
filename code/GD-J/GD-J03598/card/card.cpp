#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[500005];bool f[500005];
			int dj[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int s=1;
			for(int j=1;j<=m;j++){
				f[j]=0;
			}
			memset(dj,0,sizeof dj);
		for(int j=i;j<=n;j++){
			
			if(f[a[j]]==0){
				f[a[j]]=1;
				dj[a[j]]=s;
				s++;
			}else{
				for(int k=1;k<=n;k++){
					if(dj[a[k]]>dj[a[j]]){
						f[a[k]]=0;
						dj[a[k]]=0;
						s--;
					}
				}
				dj[a[j]]=s;
			}
		}
		for(int j=1;j<=n;j++){
			if(f[a[j]]==1){
				cnt[a[j]]++;
				f[a[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
