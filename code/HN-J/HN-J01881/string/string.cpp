#include <bits/stdc++.h>
using namespace std;
struct op{
	int h;
	char l;
}a[20000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,r=0,mn=0,pp=0;
	char ki[1000000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].h>>a[i].l;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i].h;j++){
			ki[r]=a[i].l; 
			r++;
			 
		}
}
	if(r%2!=0){
		for(int i=r-1;i>r/2;i--){
			if(ki[pp]!=ki[i]){
				mn++;
			}
			}
	}
	else {
		for(int i=r-1;i>=r/2;i--){
			if(ki[pp]!=ki[i]){
				mn++;
			}
			}
	}
	


	cout<<mn;
		return 0;
}                  
 
