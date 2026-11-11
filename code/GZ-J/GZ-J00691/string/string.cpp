//GZ-J00691 遵义市新蒲新区滨湖中学 祝国城 
#include <bits/stdc++.h>
using namespace std;
int main() {
	froepen("string.in","r","stdin");
	froepen("string.out","w","stdout");
	long s,i,a,z,b=1,x;
	string l,d;
	cin>>a;
	for(i=1;i<=a;i++){
		cin>>s>>l;
		for(z=1;z<=s;z++,b++){
			d[z]=l[1];
		}
	}for(x=0,a=1;a<=b/2;a++){
		if(d[a]!=d[b-a]){
				x++;
			}
	}
	cout<<x;
	return 0;
}

