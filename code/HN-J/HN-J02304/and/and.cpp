#include<bits/stdc++.h>
using namespace std;
//HN-J02304
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[1927];
	int min=0,max=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<a[i+1]){
			min==a[i];
		}
		else if(a[i]>a[i+1]){
			max==a[i];
		}
	}
	cout<<max-min;
	return 0;
} 
