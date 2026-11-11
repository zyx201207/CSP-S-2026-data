#include<bits/stdc++.h>
using namespace std;
int a[19999];
int sum;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[m+2]; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[a[i]]++;
		sum+=a[i];
		if(b[a[i]>1]){
			for(int j=1;j<=m;j++){
				b[i]=0;
				sum=0;
			}
			b[a[i]]++;
			sum+=a[i];
		}
		
	}
	cout<<sum;
	return 0;
}
