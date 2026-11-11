#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	int p=0,num=0;
	for(int i=1;i<=n;i++){
		num+=a[i];	
	}
	p=num/n;
	for(int i=1;i<=n;i++){
		
			if(p-a[i]>=0){
				b[i]=p-a[i];
			}
			else{
				b[i]=-(p-a[i]);
			}
		}
	
	for(int i=1;i<=n;i++){
		if(b[i]>b[i+1]){
			int tmp=b[i+1];
			b[i+1]=b[i];
			tmp=b[i];
		}
	
	for(int i=1;i<=n;i++){
	}
		while(m!=0){
			m-(p-b[i]);
			sum++;
		}
	}
	cout<<sum+1;
	cout<<n;
	return 0;
}
