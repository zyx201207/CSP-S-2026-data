#include<bits/stdc++.h>
using namespace std;
struct p{
	int x,y[1000];
};
int main(){
	p b[10];
	int n,m,a[1000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=10;j>=0;j--){
			if(a[i]>=pow(2,j)){
				b[j].y[b[j].x]=a[i];
				a[i]-=pow(2,j);
				b[j].x++;
				cout<<b[j].x<<j<<" ";
			}
		}
	}
	for(int i=10;i>=0;i--){
		if(b[i].x>=m)
		{
			int o=b[i].y[0]&b[i].y[1];
			for(int j=2;j<m;j++){
				o=o&b[i].y[j];
			}
			cout<<o;
			return 0;
		}
	}
}
