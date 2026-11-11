#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int e[200005][50];
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		int j=1;
		while(x){
			e[i][j]=x%2;
			x/=2;
			j++;
			//cout<<i<<" "<<j<<endl;
		}
	}for(int i=30;i>=1;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(e[j][i]==1&&b[j]==0){
				sum++;
			}
		}
		if(sum>=m){
			for(int j=1;j<=n;j++){
				if(e[j][i]==0){
					b[j]=1;
				}
			}
		}
	}int f=1,an;
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			if(f){
				an=a[i];
				f=0;
			}else{
				an=an&a[i];
			}//cout<<a[i]<<endl;
		}
	}cout<<an;
	return 0;

}
