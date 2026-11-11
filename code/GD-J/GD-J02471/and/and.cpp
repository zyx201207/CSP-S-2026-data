#include<bits/stdc++.h>
using namespace std;
long long a[202610];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	long long maxi=0;
	if(m==1){
		maxi=a[1];
		for(int i=2;i<=n;i++)maxi=max(a[i],maxi);
		cout<<maxi;
	}else if(m==2){
	    for(int i=1;i<n;i++)
			for(int j=i;j<=n;j++){
				if(i==j)continue;
				long long P=(a[i]&a[j]);
				maxi=max(maxi,P);
			}
		cout<<maxi;
    }else if(m==3){
    	for(int i=1;i<n;i++)
			for(int j=i;j<n;j++){
				for(int k=j;k<=n;k++){
					if(i==j||i==k||j==k||i>j||i>k||j>k)continue;
					long long P=((a[i]&a[j])&a[k]);
					maxi=max(maxi,P);
				}
			}
		cout<<maxi;
	}else if(m==n){
		int P=a[1];
		for(int i=2;i<=n;i++)P&=a[i];
		cout<<P;
	}else if(m==n-1){
		long long P=a[1];
		for(int U=1;U<=n;U++){
			for(int i=1;i<=n;i++){
				if(U==i)continue;
				P&=a[i];
			}maxi=max(maxi,P);
			P=a[1];
		}cout<<maxi;
	}return 0;
}
