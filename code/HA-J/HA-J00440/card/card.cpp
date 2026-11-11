#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool v=1;
			int g;
			for(int k=1;k<=cnt;k++){
				if(b[k]==a[j]){
					g=k;
					v=0;
				}
			}
			if(v){
				b[++cnt]=a[j];
			}else{
				for(int k=g;k<=cnt;k++){
					b[k]=0;
				}
				cnt=g;
				b[cnt]=a[j];
			}
		}
		for(int j=1;j<=cnt;j++){
			c[b[j]]++;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
