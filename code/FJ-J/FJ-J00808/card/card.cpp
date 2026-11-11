#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[300005],c[500005];
bool b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			cnt++;
			c[cnt]=a[j];
			for(int k=1;k<cnt;k++){
				if(c[k]==0){
					continue;
				}
				if(c[k]==a[j]){
					for(int q=k;q<cnt;q++){
						c[q]=0;
					}
					break;
				}
			}
		}
		for(int k=1;k<=cnt;k++){
			b[c[k]]=true;
		}
		for(int k=1;k<=m;k++){
			if(b[k]){
				sum[k]++;
			}
		}
		for(int j=1;j<=n;j++){
			c[j]=0;
			b[j]=false;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
