#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],num[N],ans[N];
int g[N],cnt;
void cle(){
	memset(num,0,sizeof(num));
	memset(g,0,sizeof(g));
	cnt=0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    for(int i=1;i<=n;i++){
    	cle();
    	for(int j=i;j<=n;j++){
    		if(num[a[j]]!=0){
    			for(int k=num[a[j]]+1;k<=cnt;k++){
    				num[g[k]]=0;
				}
				cnt=num[a[j]];
			}else{
				num[a[j]]=++cnt;
				g[cnt]=a[j];
			}
		}
		for(int j=1;j<=cnt;j++){
			ans[g[j]]++;
		}
	} 
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
