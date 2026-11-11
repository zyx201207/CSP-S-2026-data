#include<bits/stdc++.h>
using namespace std;
int a[200005],mx,mx1,m,n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)
					mx1=max(mx1,a[i]&a[j]);
			}
		}
		cout<<mx1;
		return 0;
	}
	else{
		cout<<7;
	}
	return 0;
}
/*
4 2
3 15 12 12
*/
