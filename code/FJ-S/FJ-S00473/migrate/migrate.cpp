#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("midrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int ans=0;ans<t;ans++){
		cin>>n>>d;
		int a[20000],b[20000],c[20000],sum1=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			b[i]=a[i]-a[i-1];
			c[i]=b[i]+c[i-1]; 
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int o=d,sum=0,min=10000;
				for(int x=i;x<=j;){
					o-=b[x];
					if(o<0){
						x--;
						sum++;
						o=d;
					}else{
						x++;
					} 
					if(b[x]>d){
						sum=20000;
						break;
					}
				}
				if(sum<min){
					min=sum;
				}
				if(min!=j-i){
					sum1++;
				}
			}
		}
		cout<<sum1<<endl;
	} 
	return 0;
} 
