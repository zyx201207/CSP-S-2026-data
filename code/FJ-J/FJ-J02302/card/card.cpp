#include<bits/stdc++.h>
using namespace std;
long long int n,m,have=1;
int a[600100],desk[300100],has[500100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	desk[1]=a[n];
	has[desk[1]]=n;
	
	for(int i=n-1;i>=1;i--){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=have;k++){
				if(desk[k]==a[j]){
					for(int l=k;l<=j-1;l++){
						have--;
						desk[l]=0;
					}
					desk[have+1]=a[j];
					have++;
					break;
				}
			}
			a[have+1]=a[j];
			have++;
		}
		for(int j=1;j<=have;j++){
			has[desk[j]]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<has[i]<<" ";
	}
	
	cout.flush();
	fflush(stdout);
	fclose(stdout);
	fclose(stdin);
	
	return 0;
}
