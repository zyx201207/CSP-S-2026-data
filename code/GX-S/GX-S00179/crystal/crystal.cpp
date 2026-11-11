#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long sum=0,c=0,z;
long long a[10005];


int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
		if(n%2==0){
			z=((n/2)+(n/2+1))/2;
		}
		if(n%2!=0){
			z=n/2+1;
			}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			while(a[j]<a[z]){
				a[j]+=1;
				c++;
			}	
			c=m;break;
	}
}
	for(int i=1;i<=n;i++){
		if(a[i]==a[z])
			sum+=1;
		}
	cout<<sum+1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
