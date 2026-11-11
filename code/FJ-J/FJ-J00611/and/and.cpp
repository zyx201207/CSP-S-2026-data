#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0,a[20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=0;i<n;i++){
			cin>>a[0];
			sum=max(sum,a[0]);
		} cout<<sum<<"\n";
	}
	else if(m==n){
		cin>>sum;
		for(int i=1;i<n;i++){
			cin>>a[0];
			sum=(sum&a[0]);
		} cout<<sum<<"\n";
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			cin>>a[i];
			for(int j=0;j<i;j++){
				sum=max(a[j]&a[i],sum);
			}
		} cout<<sum<<"\n"; 
	} else{
		if(m==3){
			for(int i=0;i<n;i++){
				cin>>a[i];
				for(int j=0;j<i;j++){
					for(int x=0;x<i;x++){
						if(j==x) continue;
						sum=max(a[j]&a[i]&a[x],sum);
					}
				}
			} cout<<sum<<"\n"; 
		} if(m==4){
			for(int i=0;i<n;i++){
				cin>>a[i];
				for(int j=0;j<i;j++){
					for(int x=0;x<i;x++){
						for(int y=0;y<i;y++){
							if(j==x||x==y||j==y) continue;
							sum=max(a[j]&a[i]&a[x]&a[y],sum);
						}
					}
				}
			} cout<<sum<<"\n"; 
		}
	}
	return 0;
} 
