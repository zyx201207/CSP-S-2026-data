#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,c;
	cin>>n>>m;
	long long a[n],b[m]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[j]>b[m]){
				b[m]=a[j];
			}
		}
		for(int j=0;j<n;j++){
			if(a[j]==b[m]){
				a[j]=0;
				break;
			}
		}
	}
	c=b[0];
	for(int i=1;i<m;i++){
		c=c^b[m];
	}
	cout<<c;
	return 0;
}
