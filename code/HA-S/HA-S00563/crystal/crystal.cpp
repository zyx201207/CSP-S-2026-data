#include<bits/stdc++.h>
using  namespace std;
	int n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]>a[j]){
				int hu=a[i];
				a[i]=a[j];
				a[j]=hu;
			}
		}
	}
	int z;
	if(m%2==1){
		z=(m/2+1);
	}else{
		z=m/2;
	}
	while(m!=0){
		int l=0;		
		for(int i=1;i<=n;i++){
		int cha=z-a[i];
		if(cha<0){
			cha=-cha;
		}
			if(cha< z-l){
				if(z-a[i]!=l){
				l=a[i];
				}
			}
			a[i]++;
			m--;
		}
		}
			int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]=z){
			sum++;
		}	
	}
	sum=sum-2;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
