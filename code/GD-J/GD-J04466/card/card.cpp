#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[500005],cnt;
bool b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cnt=0;
			for(int o=1;o<=n;o++){
			int k=0;
			for(int j=o;j<=n;j++){
				if(b[a[j]]==0){
					p[++k]=a[j];
					b[a[j]]=1;
				}
				else{
					for(int l=o;l<=j;l++){
						if(p[l]==a[j]){
							k=l;
						}
					}
				}
			}
			if(b[i]==1){
				cnt++;
			}
			for(int j=o;j<=n;j++){
				b[j]=0;
			}
			}
		cout<<cnt<<' ';	
	}
	
	
	return 0;
}
