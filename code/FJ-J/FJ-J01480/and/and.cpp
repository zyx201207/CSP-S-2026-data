#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,j,max1=0;
	cin>>n>>m;
	j=n-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=j;k++){
			if(a[i] and a[i+j]>max1){
				max1=a[i] and a[i+j];
			}
		}
		j--;
	}
	cout<<max1;
	return 0;
}
