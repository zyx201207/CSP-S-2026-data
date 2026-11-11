#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x=1;
	for(int i=n;i>=1;i--){
		int m1=m,s=0;
		for(int j=i-1;j>=1;j--){
			if(m1-(a[i]-a[j])>=0){
				s++;
				m1=m1-(a[i]-a[j]);
			}
			else{
				break;
			}
		}
		if(x<s){
			x=s;
		}
	}
	cout<<x+1;
	
	return 0;
}
