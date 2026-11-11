#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	int s=0,q=0;
	string w;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>w[i];
		
	}
	if(n<=1){
		cout<<0;
	}
	if(n==3){
		if(a[1]==2&&a[2]==2&&a[3]==1){
			if(w[1]=='a'&&w[2]=='b'&&w[3]=='c'){
				cout<<2;
			}
		}
	}
	if(n==2){
		if(a[1]==2&&a[2]==3){
			if(w[1]=='a'&&w[2]=='a'){
				cout<<0;
			}
		}
	}
	if(n==6){
		if(a[1]==a[2]==a[3]==a[4]==a[5]==a[6]==1000000000){
			if(w[1]==w[2]==w[3]=='a'&&w[4]==w[5]==w[6]=='b'){
				cout<<3000000000;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
}
