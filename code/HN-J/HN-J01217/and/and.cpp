#include<bits/stdc++.h>
using namespace std;
int n,m,c,e;
int d[100002];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n,greater<int>());
	if(m==1){
		cout<<a[0];
	}else if(m==n){
		c=a[0];
		for(int i=1;i<n;i++){
			c=c&&a[i];
		}cout<<c;
		return 0;
	}else if(m==n-1){
		c=a[0];
		for(int i=1;i<n-1;i++){
			c=c&&a[i];
		}cout<<c;
		return 0;
	}else if(m==2){
		cout<<a[0]&&a[1];
	}
	return 0;
} 
//for(int i=0;i<n;i++){
			//for(int j=0;j<n;j++){
				//if(i!=j){
					//d[e]=a[i]&&a[j];
					//e++;
				//}
			//}
		//}sort(d,d+e,greater<int>());
		//cout<<d[0];


