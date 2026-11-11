//GZ-S00403 观山湖第一高级中学 王华鑫 
#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		int a[n+10],b[n+10];
		for(int j=1;j<=n;j++){
			cin>>a[j];
			b[1]=a[1];
			b[i]=a[i]-a[i-1];
			
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;i++){
				if(b[j]<=d)
			}
		}
	}
	
	return 0; 
}
