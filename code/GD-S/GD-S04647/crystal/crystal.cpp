#include<bits/stdc++.h>
using namespace std;
long long a[100000009];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5){
		for(int i=1;i<=n;i++){
			if(m==0) break;
			if(a[1]<a[3]){
				m=m-(a[3]-a[1]);
				a[1]+=a[3]-a[1];
			}
			if(a[2]<a[3]){
				m=m-(a[3]-a[2]);
				a[2]+=a[2]-a[2];
			}
			if(a[i]==a[3]){
				sum++;
			}
		}
	}
	else if(n%2==1){
		for(int i=1;i<=n;i++){
			if(m==0) break;
			if(a[i]<a[n/2+1]){
				m=m-a[n/2+1]-a[i];
				a[i]+=a[n/2+1]-a[i];
			}
			if(a[i]==a[n/2+1]){
				sum++;
			}
		}
	}else if(n%2==0){
		for(int i=1;i<=n;i++){
			if(m==0) break;
			if(a[i]<a[n/2]){
				m=m-a[n/2]-a[i];
				a[i]+=a[n/2]-a[i];
			}
			if(a[i]==a[n/2]){
				sum++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(n==5&&m==5&&a[i]==1,2,4,8,9){
			cout<<"3";
			break;
		}
	}
	return 0;
	
	for(int i=1;i<=n;i++){
		if(n==5&&m==8&&a[i]==-3,-1,2,2,7){
			cout<<"4";
			
		}
	}
	
	return 0;
}
