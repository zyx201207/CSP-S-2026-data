#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001];
int ans[500001],alans[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}for(int t=1;t<=n;t++){
		int cnt=n;
		for(int i=t;i<=n;i++){
			bool f=0;
			for(int j=1;j<=cnt;j++){
				if(a[i]==b[j]){
					cnt=j;
					f=1;
					for(int k=j+1;k<=n;k++){
						b[k]=0;
					}break;
				}
			}if(f==0){
				cnt++;
				b[cnt]=a[i];
			}
		}for(int i=1;i<=cnt;i++){
			ans[b[i]]=1;
		}for(int i=1;i<=m;i++){
			alans[i]+=ans[i];
		}for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
	}for(int i=1;i<=m;i++){
		cout<<alans[i]<<' ';
	}
	return 0;
}
