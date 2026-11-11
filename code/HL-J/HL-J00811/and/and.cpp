#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200005],Max=0,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)cin>>a[i];
    if(n==m){
    	for(int i=1;i<=m;i++){
    		a[i+1]=a[i]&a[i+1];
		}
		cout<<a[m];
		return 0;
	}
	if(n==1){
		Max=a[1];
		for(int i=2;i<=m;i++){
			if(a[i]>Max){
				Max=a[i];
			}
		}
		cout<<Max;
	}
	if(n==2){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				sum=a[i]&a[j];
				if(sum>Max){
					Max=sum;
				}
			}
		}
		cout<<Max;
	}
}