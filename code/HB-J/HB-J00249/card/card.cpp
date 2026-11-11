#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
bool v1[500005],v2[500005];
int aa[5000005];
int ans[5000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!v2[j]){
				v2[j]=1;
				aa[j]=j;
			}else if(v2[j]){
				for(int k=aa[j];k<j;k++){
					v1[k]=1;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(!v1[j]) ans[j]++; 
		}
		memset(v1,0,sizeof(v1));
		memset(v2,0,sizeof(v2));
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
//4 3
//1 2 1 3
