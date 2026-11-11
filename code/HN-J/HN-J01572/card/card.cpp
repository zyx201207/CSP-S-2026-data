#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],t[500010],boo[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int sum=0;
		memset(boo,0,sizeof(boo));
		for(int j=i;j<=n;j++){
			sum++;
			if(boo[a[j]]==0){
				boo[a[j]]=sum;
			}
			else{
				sum=boo[a[sum]];
				for(int k=sum;k<=j;k++){
					boo[a[k]]=0;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(boo[j]!=0) t[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
	//Trick||Treat!
}
