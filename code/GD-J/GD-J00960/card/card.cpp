#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005];
long long b[500005];
long long d[500005],bj[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(bj,0,sizeof(bj));
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				for(int p=b[a[j]]+1;p<=j-1;p++){
					a[p]=0;
					if(b[a[p]]>b[a[j]]&&b[a[p]]<j){
						b[a[p]]=0; 
					}
				}
			}else{
				b[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(bj[a[j]]==0&&a[j]!=0){
				d[a[j]]++;
				bj[a[j]]++;
			}
			a[j]=c[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
/**/
