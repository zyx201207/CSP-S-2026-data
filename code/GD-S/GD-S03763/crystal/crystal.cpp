#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","g",stdout);
	int n,m,a[1000005]={0},d=0,c=0,f=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
		for(int i=n;i>1;i--){
			d=0;
			f=1;
			for(int j=i-1;j>0;j--){
			    d=d+a[i]-a[j];
			    if(d>m){
			    	break;
				}
				else{
					f++;
				}
			}
			if(f>c){
				c=f;
			}
		}
	cout<<c;
	return 0;
}
