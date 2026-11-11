#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+9],c[n+9],b[n+9];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
		c[i]=0;
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++) b[i]=0;
		for(int i=j;i<=n;i++){
			if(b[a[i]]==1){
				b[i]=0;
			}else{
				b[i]=1; 
			}
		}
		for(int i=n;i>=j;i--){
			if(b[i]==1){
				c[a[i]]++;
			}
			if(b[i]==0){
				c[a[i]]++;
				break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
