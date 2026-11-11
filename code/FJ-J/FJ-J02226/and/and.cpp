#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int a[200005];
	int m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int s=0;
	for(int i=0;i<n;i++){
		s+=a[i];
	}
	s/=n;
	int x=100000;
	for(int i=0;i<n;i++){
		if(s>a[i]){
			continue;
		}
		if(a[i]-s<x){
			x=a[i]-s;
		}
	}
	int c=0;
	int y=100000;
	int b[200005];
	for(int i=0;i<n;i++){
		if(a[i]-s==x){
			b[c]=a[i];
			c++;
		}
	}
	for(int i=0;i<=c;i++){
		if(b[i]<y){
			y=b[i];
		}
	}
	cout<<y;
	return 0;
}
