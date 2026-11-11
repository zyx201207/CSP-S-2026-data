//Trick||Treat!
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],b[1005],cnt=1,cnta,c[1005];
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[cnt]=a[cnta];
		for(int j=1;j<=cnt;j++){
			if(b[cnt]==b[j]){
				cnt=j+1;
				break;
			}
		}
		cnta++;
	}
	for(int i=1;i<=cnt;i++){
		c[b[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}





