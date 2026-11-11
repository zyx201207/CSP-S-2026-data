#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ai=0;
	char ci;
	cin>>n;
	int b=0;
	char a[n];
	for(int i=0;i<n;i++){
		b+=ai;
		cin>>ai;
		cin>>ci;
		a[ai+b];
		for(int j=0;j<ai;j++){
			a[j+b]=ci;
		}
	}
	int x=0;
	for(int i=0;i<(b+ai)/2;i++){
		if(a[i]==a[b+ai-1-i]){
			x++;
		}
	} 
	int c=(b+ai)/2;
	if(x==c){
		cout<<0;
	}
	else{
		cout<<c-x;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
