#include<bits/stdc++.h>
using namespace std;
int n,m,vis[100],_max=0,a[100],rest,rst;

void _and(int rst){
	rest--;
	for (int i=0;i<n;i++){
		if (vis[i]==0){
			vis[i]=1;
			rst=rst&&a[i];
			_and(rst);
		}
	}
	if (rest==0){
		if (rst>_max){
			_max=rst;
		}

	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for (int i=1;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		rest=m;
		for (int j=0;j<n;j++){
			vis[j]=0;	
		}			
		vis[i]=1;
		_and(a[i]);
	}
	cout<<_max;
}
