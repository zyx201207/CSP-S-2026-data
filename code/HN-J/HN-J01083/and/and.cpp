#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int max1=-1,max2=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
	}
	if(m==1){
		cout<<max1;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				max2=max(max2,a[i]&a[j]);
			}
		}
		cout<<max2;
		return 0;
	}
	return 0;
}
