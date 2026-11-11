#include<iostream>
#include<cstdio>
using namespace std;
int a[200005],ma[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,maxa=-9999;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ma[i]=a[i]&a[1];
		int mai=a[i];
		for(int k=1;k<m;k++){
			for(int j=2;j<=n;j++){
				if(mai&a[j]>ma[i]&&j!=i){
					ma[i]=mai&a[j];
				}
			}
			mai=ma[i];
		}

		if(ma[i]>maxa){
			maxa=ma[i];
		}
	}
	cout<<maxa<<endl;
	return 0;
} 
