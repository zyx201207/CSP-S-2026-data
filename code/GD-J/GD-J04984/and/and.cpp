#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],cnt=1;
int Max=-1e9,Maxi,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(a[i]>Max){
				Max=a[i];
				Maxi=i;
			}
		}
		b[cnt++]=Max;
		a[Maxi]=0;
		Max=0;
	}
	for(int i=1;i<=cnt-1;i++){
		if(i==1){
			sum=b[i];
		}else{
			sum&=b[i];
		}
	}
	cout<<sum;
	return 0;
} 
