//GZ-S00226 遵义市第二十一中学 童俊铭  
#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m,b=0,c=0;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
			}
		}
	}
	b=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]*i-(b+a[i])==m){
			c=i;
		}
		b+=a[i];
	}
	cout<<c;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
