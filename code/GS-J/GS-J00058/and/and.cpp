#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int cun[1005];
int cum[1005];
int d[1005];
int sum[1005];
int b=0;
int main(){
	freopen("and.in ","r",stdin);
	freopen("anf.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i];
		while(a[i]!=0){
			cun[i]=a[i]%2;
			a[i]/=2;
			i+=1;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			if(cun[j]<=cun[j+1]){
				cun[j]=cun[j+1];
				cun[j+1]=cun[j];
			}
			for(int k=1;k<=8;k++){
				if(cun[j]/10*(k-1)==cun[j+1]/10*(k-1)){
					cum[k]=1;
				}
				else{
					cum[k]=0;
				}
			}
			while(d[i]!=0){
				for(int g=1;g<n;g++){
					cum[j]*=2;
				sum[i]+=cum[j];
				d[i]/=10;
			}
		}
		}
	}
	b=0;
	for(int i=1;i<=n;i++){
		b=max(sum[i],b);
	}
	cout<<b-2;
	return 0;
}
