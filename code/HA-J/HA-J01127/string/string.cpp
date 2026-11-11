#include<bits/stdc++.h>
using namespace std;
int n,math[25000000];
string english[25000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=0;i<n;i++){
		cin>>math[i]>>english[i];
	}
	int j=n;
	for(int i=0;i<n;i++){
		if(english[i]!=english[j]){
			if(math[i]>math[j]) cout<<math[i];
			if(math[i]<math[j]) cout<<math[j];	
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
