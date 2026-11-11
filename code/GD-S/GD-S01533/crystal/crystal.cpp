#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,h=1,c=1;
	freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	//ÊäÈë 
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(1){
		sort(a,a+n);
		m-=3;
		a[0]+=3;
		if(m==0){
			break;
		}
	}
	for(int i=1;i<n;i++){
		if(a[0]==a[i]){
			c+=1;
		}
	}
	cout<<c<<endl;
	return 0;
} 
