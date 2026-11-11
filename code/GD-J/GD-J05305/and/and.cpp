#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,k,sum=0,sum1=0,num,flag;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>sum){
			sum=a[i];
			k=i;
		}
	}
	a[k]=0;
	for(int i=1;i<m;i++){
		sum1=0;
		for(int i=1;i<=n;i++){
			num=2,flag=0;
			while(num<=a[i]){
				if(num==a[i]) flag=1;
				num*=2;
			}
			if(flag==1) continue;
			if(a[i]==0) continue;
			if(sum&a[i]>sum1){
				sum1=sum&a[i];
				k=i;
			}
		}
		a[k]=0;
		sum=sum1;
	}
	cout<<sum;
	return 0;
}
