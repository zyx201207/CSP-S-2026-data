#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	int n,m;
	cin>>n>>m;
	long long a[m];
	for(int i=0;i<m;i++){
		a[i]=0;
	}
	for(int i=0;i<n;i++){
		int x;
		cin>>x; 
		if(x>a[0]){
			for(int j=m;j>0;j--){
				a[m-1]=a[m-2];
			}
			x=a[0];
		}
	}
	int ma=a[0];
	for(int i=1;i<=m;i++){
		ma=(ma&a[i]);
	}
	cout<<ma;
	return 0;
}

