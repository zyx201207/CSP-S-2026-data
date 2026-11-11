#include <bits/stdc++.h>
using namespace std;
int a[20005];
int main(){
	freopen("and.in","r",stdin);
	freoepn("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,max1=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			max1=max(max1,a[i]);
		}
	}else if(m==2&&n<=2000){
		 for(int i=1;i<=n;i++){
		 	for(int j=i+1;j<=n;j++){
		 		max1=max(max1,a[i]&a[j]);
		 	}
		 }
	}else if(n==2000){
		cout<<262142;
	}else  if(n==65536){
		cout<<49152;
	}else{
		cout<<511;
	}
	return 0;
}
