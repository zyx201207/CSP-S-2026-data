#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],bf[100005],b[100005];
int ans[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int xn=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		bf[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		int kl=0;
		for(int j=1;j<=xn;j++){
			for(int l=1;l<=j-1;l++){
				if(b[l]==a[kl]&&b[l]!=0){
					for(int k=l;k<=xn;k++){
						a[k]=0;
					}
					j=l;
					cout<<b[l]<<" ";
				}
			}
			b[kl]=a[j];
			a[j]=0;
			kl++;
		}
		for(int j=1;j<=xn;j++){
			ans[b[j]]++;
		}
		xn=n;
		for(int i=1;i<=n;i++){
			a[i]=bf[i];
		}
		cout<<"\n";
	} 
	for(int i=1;i<=m;i++){
		cout<<ans[m]<<" ";
	}

	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
