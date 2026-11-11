#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sp[500005],b[300005],bi[300005],s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sp[i]=i;
	}
	for(int i=1;i<=n;i++){
		if(!b[a[i]]){
			b[a[i]]=1;
			bi[a[i]]=i;
		}
		else{
			sp[bi[a[i]]]=i;
			bi[a[i]]=i;
		}
	}
	for(int k=1;k<=n;k++){
		memset(b,0,sizeof(b));
		for(int i=k;i<=n;i++){
			while(!b[i]){
				b[i]=1;
				i=sp[i];
			}
			s[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
/*10 3
3 1 2 1 3 2 3 1 2 1
*/
