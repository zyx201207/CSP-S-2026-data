//GZ-J00691 遵义市新蒲新区滨湖中学 祝国城 
#include <bits/stdc++.h>
using namespace std;
int main() {
	froepen("and.in","r","stdin");
	froepen("and.out","w","stdout");
	int m,x;
	cin>>m>>x;
	int a[m+1]={0},s,i;
	for(i=1;i<=m;i++){
		cin>>a[i];
	}
	for(i=m;i>0;i--){
		for(int c=i;c>0;c--){
			if(i>1&&a[i]>a[c]){
				swap(a[i],a[c]);
			}
		}
	}cout<<a[x];
	return 0;
}
