#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a[200010],x,max1=0;
	bool yes1=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	x=a[n];
	for(int i=1;i<=n-1;i++){
		if(a[i]==x){
			yes1=false;
			max1=min(i,max1)
		}
	}
	if(!yes1){
		cout<<i-1<<endl<<n;
	}
	return 0;
}
