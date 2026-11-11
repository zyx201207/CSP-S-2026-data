#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],b[m+1],x[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
	}
	for(int i=1;i<=n;i++){
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			x[j]=a[j];
			if(j!=i){
				int num=0;
				for(int k=1;k<j;k++){
					if(x[j]==x[k]){
						for(int s=k;s<j;s++){
							x[s]=0;
						}
						break;
					}else{
						num++;
					}
					if(num==j-1)break;
				}
			}
		}
		for(int j=1;i<=n;j++){
			b[x[j]]++;
		}
		for(int j=1;j<=n;j++){
			x[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i];
	}
	return 0;
}
/*4 3
1 2 1 3*/
