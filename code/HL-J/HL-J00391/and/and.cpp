#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int ans=0;
int mian(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",n,m);
	for(int i=0;i<n;i++){
		scanf("%d",a[i]);
	}
	for(int j=0;j<n;j++){
		for(int q=0;q<n;q++){
			if(a[j]==a[q]){
				ans+=1;
			}
		}
	}
	sort(a[0],a[n-1]);
	if(ans>=m){
		printf("%d",m);
	}
	else{
		printf("%d",a[m-1]);
	}
	return 0;
}
