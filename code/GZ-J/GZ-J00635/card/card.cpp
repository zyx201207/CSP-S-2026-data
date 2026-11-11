//GZ-J00635 兴义市弘毅中学 廖鑫豪 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500500],b[300300],c[300300],d[300300],e[300300];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
	cin>>a[i];
	b[a[i]]++;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(b[a[j]]==1){
				c[j-i+1]=a[j];
			}
			else{
				for(long long k=1;k<=j-i;k++){
					if(c[k]==a[j]){
						for(long long p=k;p<=j-i;p++){
							c[p]=0;
						}
					}
				}
				c[j-i+1]=a[j];
			}
		}
		for(long long j=1;j<=n;j++){
			if(c[j]!=0){
				e[c[j]]=1;
			}
			c[j]=0;
		}
		for(long long j=1;j<=m;j++){
			if(e[j]){
				d[j]++;
			}
			e[j]=0;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	cout<<'\n';
	return 0;
} 
