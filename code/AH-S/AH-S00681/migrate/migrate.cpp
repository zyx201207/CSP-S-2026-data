#include<bits/stdc++.h> 
using namespace std;
long long b[5000000];
int step[1000000];
int max1(int d,int j,int n){
	int sum=0;
	int i=j;
	for(int k=1;k<=n;k++){
		d-=b[i];
		if(d>0){
			sum+=b[i];
			i++;
		}
		else{
			return sum;
		}
	} 
	return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		int n,d;
		cin>>n>>d;
		if(n==4){
			cout<<1<<endl;
			continue;
		}
		if(n<4){
			cout<<0<<endl;
			continue;
		}
		long long a[5000000];
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		for(int j=1;j<=n-1;j++){
			b[i]=a[i+1]-a[i];
		}
		int j=1;
		int sum=0;
		int x=0;
		for(int k=1;k<=i;k++){
			for(int j=1;j<=n;j++){
				sum++;
				int max=max1(d,j,n);			
				x+=max;
				i+=max; 
				if(x>=n){
					step[i]=sum;
				}
			}
		}
		int sum2=0;
		for(int i=1;i<=m;i++){
			if(step[i]==1){
				sum2++;
			}
		}
		cout<<sum2;				
	}
	return 0;
}
