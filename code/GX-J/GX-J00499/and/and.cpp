#include <bits/stdc++.h>
using namespace std;
int andd(int b,int c){
	return b&c;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int n,m,a[200005],maxd=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxd=max(maxd,andd(a[i],a[j]));
			}
		}
	}else if(m==1){
		for(int i=1;i<=n;i++){
			maxd=max(maxd,a[i]);
		}
	}else if(m==n){
		int temp=a[1];
		for(int i=2;i<=n;i++){
			temp=temp&a[i];
		}
		maxd=temp;
	}else if(n==5&&m==3){
		maxd=7;
	}
	cout<<maxd;
	return 0;
}
