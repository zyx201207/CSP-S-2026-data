#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n[5000],m,a,b,c;
	cin>>m;
	for(int i=0; i<5;i++){
		cin>>n[i];
	    if(n[i]>n[i+1]){
			b=n[i]-n[i+1]
			n[i]=n[i+1]
			m=m-b;
	    }
		if(n[i]<n[i+1]){
			c=n[i+1]-n[i]
			n[i]=n[i+1]
			m=m-c;
	    }
	    if(n[i]=n[i+1]){
			a++;
	    }
		}
	cout<<a;
	return 0;
}
