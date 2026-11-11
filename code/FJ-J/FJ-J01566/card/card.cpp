#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=300005;
int n,m,a[N],b[M],da[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n<100005){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(b[a[j]]==0){
					b[a[j]]=j;
				}
				else{
					for(int k=b[a[j]];k<j;k++){
						b[a[k]]=0;
					}
					b[a[j]]=j;
				}
			}
			for(int i=1;i<=m;i++){
				if(b[i]!=0){
					da[i]++;
				}
			}
			for(int i=1;i<=n;i++){
				b[i]=0;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<da[i]<<" ";
		}
	}
	else if(n<=2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int nb;
		if(a[n]==1){
			cout<<n<<" "<<nb;
		} 
	}
	return 0;
} 
