#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	cin>>n;
	cin>>m;
	long long a[n],x[n];
	
	for(int i=0;i<n;i++){
	
		cin>>a[i];
	}for(int i=n-1;i>=0;i--){
		int  sum=m,j=0,ans=1;
		while(sum>=0){
			if(sum<0){
				break;
			}
			else if(i-j<0)
			break;
			j++;
			if(a[i]-a[i-j]<0)
			break;
			sum=sum-(a[i]-a[i-j]);
			ans++;
		}
			x[i]=ans;
		
	}
	for(int j=0;j<n;j++){
	
	for(int i=1;i<n;i++){
	if(x[i-1]>x[i]){
			int t=x[i-1];
			x[i-1]=x[i];
			x[i]=t;

		}
}
}
	cout<<x[n-1];
	return 0; 
}
