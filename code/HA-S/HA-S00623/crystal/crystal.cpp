#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	int ma=0;
	for(int i=2;i<n;i++){
		for(int j=1;j<i;j++){
			int sum=0,num=0;
			for(int k=j;k<=i;k++){
				sum+=a[k];
			}
			if((sum+m)%(i-j+1)==0&&(sum+m)/(i-j+1)==a[i]){
				for(int k=0;k<=m;k++){
					if((sum+m-a[i]-k)%(i-j)==0&&(sum+m-a[i]-k)/(i-j)==a[i]+k){
						num=i-j+1;
					}
				}
				
			}
			
			
			if(num>ma)ma=num;
		}
	}
	cout<<ma;
	return 0;
}
