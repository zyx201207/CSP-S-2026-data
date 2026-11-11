#include<bits/stdc++.h>
using namespace std;
int a[10001]; long long sum=0;long long y=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a[i];
		if(a[i]<0){
			a[i]=0-a[i];
			
		}
		sum+=a[i];
	}
	y=(sum+m)/n;
	cout<<y;
	return 0;
}
