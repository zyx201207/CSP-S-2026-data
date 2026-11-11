//GZ-J00169 遵义市第一初级中学 梁悠然 
#include <iostream>
using namespace std;
int main (){
	int n,m,max=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=i+m-1;i++){
			a[i]=a[i]&a[j];
		}
		if(a[i]>max){
			max=a[i];
		}
	}
	cout<<max;   
}
	
