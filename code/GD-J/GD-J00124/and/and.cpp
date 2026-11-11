#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,zd=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j]){
	   		int t=a[i];
			a[i]=a[j];
			a[j]=t;
			}
		}
    }
    cout<<a[(1+n)/2];

	return 0;
}
