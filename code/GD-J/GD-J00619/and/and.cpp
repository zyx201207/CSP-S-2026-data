#include<bits/stdc++.h> 
using namespace std;
char c[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=-1,z=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		z+=1;
		c[i]=n;
	}
	if(m=1){
		for(int i=0;i<z;i++){
			if(c[i]>max) max=c[i];
		}
		cout<<max;
	}
	else {
		cout<<7;
	}
	return 0;
}
