#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,x=0,y=0,z=0;
	int a[5000000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			y=m;
			y-=a[i]-a[j];
			if(y>=0){
				x++;
				if(x>z){
					z=x;
				}
			}
			else break;
		}
	}
	cout<<z;
	return 0;
}
