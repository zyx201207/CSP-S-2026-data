#include<bits/stdc++.h>
using namespace std;
void pai(int c,int *a){
	for(int i=0;i<c;i++){
		for(int j=0;j<c;j++){
			if(a[i]>=a[j]){
				int b=a[j];
				a[j]=a[i];
				a[i]=b;
			}
		}
	}
};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[n+5],sum;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	pai(n,a);
	sum=a[0];
	for(int i=1;i<m;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
