#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500000]={0},d=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int b=m,c=0;
		for(int j=i;j>=0;j--){
			b=b-a[i]+a[j];
			c++;
			if(b<=0){
				if(c>d){
					d=c;
				}
				break;
			}
			
		}
	}
	cout<<d;
	return 0;
}
