/*#include<bits/stdc++.h>
using namespace std;
int n,m,z[500050],y[300050],x[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>z[i];
		y[z[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=n,q=1;j>=1 and q<=i;j--,q++){
			if(y[z[j]]!=j){
				for(int k=y[z[j]];k<=n;k++){
					x[z[k]]++;
				}
				break;
			}if(q==i){
				for(int k=j;k<=n;k++){
					x[z[k]]++;
				}
				break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<x[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int n,m,z[500050],y[300050],x[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>z[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			y[j]=0;
		}
		int k=i;
		for(int j=i;j<=n;j++){
			if(y[z[j]]==1){
				k=j;
			}
			y[z[j]]=1;
		}
		for(;k<=n;k++){
			x[z[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<x[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
