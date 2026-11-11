#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],b[300010],s[500010],st;
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
    	for(int j=i;j<=n;j++){
    		if(b[a[j]]==i){
    		while(s[st]!=a[j]) st--;
    		b[a[j]]=0;
			}
			else{
			s[++st]=a[j];	
			b[a[j]]=i;
			}
		}
		while(st>0){
			ans[s[st]]++;
			st--;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
