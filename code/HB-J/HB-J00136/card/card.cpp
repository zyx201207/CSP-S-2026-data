#include<bits/stdc++.h>
using namespace std;
int a[500007],b[300007],c[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	//int n1=n;
	for(int k=0;k<n;k++){
		int sum=0;
		for(int i=k;i<=n;i++){
			if(b[a[i]]==0)b[a[i]]=sum++;
			else{
				int x=b[a[i]];
				for(int j=1;j<=n;j++){
					if(b[j]>=x){
						sum--;
						b[j]=0;
					}
				}
				b[a[i]]=sum++;
			}
		}
		for(int i=1;i<=m;i++){
			if(b[i]!=0){
				c[i]++;
				//cout<<b[i]<<" ";
			}
			b[i]=0;
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
