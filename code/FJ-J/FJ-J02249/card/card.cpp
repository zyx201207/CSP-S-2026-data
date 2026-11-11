#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int s=0;
		int b[300005]={0};
		for(int j=i;j<=n;j++){
			s++;
			b[a[j]]+=1;
			if(b[a[j]]==2){
				s=1;
				b[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			c[j]+=b[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
