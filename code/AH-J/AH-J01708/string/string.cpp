#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	//	freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,s=0,max=0;
	struct{
		int a;
		char b;
	
	}c[21000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].a>>c[i].b;
	}
	for(int i=1;i<=n;i++){
		if (c[i].a>max)
		max=c[i].a;
	}
	for(int i=1;i<=n;i++){
		s+=c[i].a;
	}
	if (max>s/2){
		cout<<s-max;
	}else{
		cout<<s/2;
	}
	return 0;
}
