#include<bits/stdc++.h>
#include<vector>
using namespace std;
int n,m,sum;
int a[500005],b[300005];
bool fb[300005];
int c[500005];//桌上的牌 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[i]=-1;
	}
	for(int i=1;i<=n;i++){
		sum=0;
		for(int i=1;i<=n;i++){
			c[i]=-1;
		}
		for(int i=1;i<=m;i++){
			fb[i]=0;
		}
		for(int j=i;j<=n;j++){//当前打出的牌 
			bool f=1,num=0;
			for(int z=0;z<sum;z++){
				if(c[z]==a[j]){
					f=0;
				}
				if(!f){
					c[z]=-1;
					num++;
				}
			}
			sum-=num;
			c[sum]=a[j]; 
			sum++;
		}
		for(int j=0;j<sum;j++){
			if(!fb[c[j]]){
				b[c[j]]+=1;
				fb[c[j]]=1;
			}
		}
	}for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}


