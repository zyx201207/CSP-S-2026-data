#include<bits/stdc++.h>																															//	awa          	
using namespace std;
int n,m,a[100009],b[100009],c[100009],tp=0,ans=-1,anss=0,sum=0;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		c[i]=b[i];
	}
	for(int i=1;i<=n;i++){
		tp=m;
		anss=1;
		for(int k=2;tp!=0;){
			if(b[i]==b[k]){
				anss++;
				tp--;
				k++;
			}
			else{
			b[i]++;
			tp--;
			}
		}
		if(anss>ans)
		ans=anss;
		for(int j=1;j<=n;j++){
			b[j]=c[j];
		}
	}
	cout<<ans;
	return 0;
}