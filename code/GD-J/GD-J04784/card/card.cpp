#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		int L=1;
		for(int j=i;j<=n;j++){
			int index=-1;
			for(int k=1;k<=L;k++){
				if(b[k]==a[j]){
					index=k;
					break;
				}
			}
			if(index==-1) b[L++]=a[j];
			else{
				int t=0;
				L--;
				for(int k=index;k<=L;k++){
					b[k]=0;
					t++;
				}
				L-=t;
				b[L++]=a[j];
			}
		}
		for(int j=1;j<=m;j++){
			for(int k=1;k<=L;k++){
				if(b[k]==j){
					ans[j]++;
					break;
				}
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<endl;
	}
	return 0;
}
