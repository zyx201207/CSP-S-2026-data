#include<bits/stdc++.h>
using namespace std;
int x[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d,sum=0,flag=0,Max=INT_MIN;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			if(j==2){
				Max=x[j]-x[j-1];
			}
			if(j==3){
				if(Max!=x[j]-x[j-1])flag=1;
			}
		}
		if(flag==0){
			sum=0;
		}
		else if(n%2==0){
			for(int j=1;j<n;j++){
				for(int k=j+2;k<=n;k++){
					if(x[k]==x[j]+d+1){
						sum++;
					}
				} 
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
