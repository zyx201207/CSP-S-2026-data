// Gz-JOO614 遵义市第四初级中学 李浩然  
#include<bits/stdc++.h>
using namespace std;int z[10000]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	int a,b;
	cin>>a>>b;
	map<int,int>m;
	for(int i=0;i<a;i++){
		cin>>z[i];
		
	}
	sort(z+0,z+a);
	cout<<z[a-b];
	

}
