#include<bits/stdc++.h>
using namespace std;

int l;string s;
int main(){
	
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	
	cin>>l;int m=1;
	
	int a[10005];
	for(int i=1;i<=l;i++){
		char b;
		cin>>a[i]>>b;
		for(int y=1;y<=a;y++){
		    s[m]=b;
		}
	}
	
	
	if((a[1]==a[l]&&l=3)&&(a[1]==a[l]&&a[2]==a[l-1]&&l=5)){
		cout<<"0" 
	}
	if(a[1]>a[l]&&a[l]<a[1]){
		cout<<l-a[i];
	}
	return 0;
}



