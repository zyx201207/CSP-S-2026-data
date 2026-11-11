#include<bits/stdc++.h>
using namespace std;
int n,m,a[50001]={},b,c=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	b=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			if(a[i]+b>=a[j]&&i!=j&&a[j]>=a[i]){
				b=b-a[j]+a[i];
				a[i]=a[j];
				c++;
				break;
			}
		}
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
