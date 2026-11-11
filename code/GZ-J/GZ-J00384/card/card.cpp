//GZ-J00384 Îºð©éª 
#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,m,k=1,flag=-1;
int a[N],b[N],c[N];

int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	
	while(n--){
		for (int i=k;i<=n;i++){
			for (int j=k;j<=i-1;j++){
				if(a[i]!=a[j] && flag==-1) b[i]=a[i];
				else{
					flag=1;
					b[j]=0;
				}
			}
			k++,flag=-1;
		}
		k=1;
		for (int i=1;i<=n;i++){
			if(b[i]!=0) c[i]++;
			b[i]=0;
		}
	}
	
	c[a[n]]=n;
	
	for (int i=1;i<=n;i++){
			if(c[i]!=0){
				printf("%d ",c[i]);
			}
	}
	
	return 0;
}
