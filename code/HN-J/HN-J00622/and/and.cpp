#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c=0;
	int a[n];
	for(int q=0;q<n;q++){
		cin>>a[q];
	}//*1073741824
	for(int q=1073741824;q>0;q/=2){
		int w=0;
		for(int e=0;e<n;e++){
			if(q<=a[e]){
				w++;
			}
		}
		if(w>=m){
			c+=q;
			for(int e=0;e<n;e++){
				if(q>a[e]){
					a[e]=0;
				}
				else{
					a[e]-=q;
				}
			}
		}
		for(int e=0;e<n;e++){
			if(q<=a[e]){
				a[e]-q;
			}
		}
//		cout<<q<<":"<<c<<"\n";
	}
	cout<<c;
	return 0;
} 
