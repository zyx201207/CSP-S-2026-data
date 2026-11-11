#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int st[1500005];
int wz[500005];
int cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
		int l=1,r=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				wz[j]=0;
			}
			for(int j=i;j<=n;j++){
				if(wz[a[j]]!=0){
					for(int k=wz[a[j]]+1;k<=r;k++){
						wz[st[k]]=0;
					}
					r=wz[a[j]];
					
				}
				else {
					st[++r]=a[j];
					wz[a[j]]=r;
				}
			}
			for(int j=l;j<=r;j++){
				//cout<<st[j]<<' ';
				cnt[st[j]]++;
				wz[st[j]]=0;
				st[j]=0;
				
			}
			l=1,r=0;
			//cout<<"\n";
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<' ';
		}
	return 0;
}
