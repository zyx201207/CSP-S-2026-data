#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=5e5+1,MAXM=3e5+1;
int ans[MAXM]={0},a[MAXN]={0},s[MAXN]={0},first[MAXM]={0},n,m,top=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		top=1;
		memset(s,0,sizeof(s)); 
		memset(first,0,sizeof(first));
		for(int j=i;j<=n;j++)
			if(!first[a[j]]){
				s[top]=a[j];
				first[a[j]]=top;
				top++;
			}
			else{
				top=first[a[j]]+1;
			}
		for(int k=1;k<top;k++) ans[s[k]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
