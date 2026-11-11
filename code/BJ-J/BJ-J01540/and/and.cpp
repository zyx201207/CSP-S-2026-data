#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[200001],max_=INT_MIN;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)
			max_=max(a[i],max_);
		return cout<<max_,0;
	}
	if(n==m){
		int b=a[1];
		for(int i=2;i<=n;i++)
			b=b&a[i];
		return cout<<b,0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				max_=max(i&j,max_);
		return cout<<max_,0;
	}
	if(m==3){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					max_=max(i&j&k,max_);
		return cout<<max_,0;
	}
	return 0;
}