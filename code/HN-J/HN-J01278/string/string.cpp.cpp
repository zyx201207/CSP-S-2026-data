#include<bits/stdc++.h>
using namespace std;
int n,a[200005],wow,p;
char c[200005],ans[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			ans[p]=c[i];
			p++;
		}
	}
	for(int i=0;i<=n/2;i++){
			if(ans[i]!=ans[n-i]){
				wow++;
			}
	}
	cout<<wow;
	return 0;
} 
