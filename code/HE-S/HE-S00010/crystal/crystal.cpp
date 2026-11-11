#include<bits/stdc++.h>
using namespace std;

const int N=5e3+10;
int n;
int m,a[N],adf[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		adf[i]=a[i]+adf[i-1];
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			if(a[j]*(i-1)-(adf[j-1]-adf[j-i])<=m){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
