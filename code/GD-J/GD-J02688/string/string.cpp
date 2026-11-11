#include<bits/stdc++.h>
using namespace std;
int a[10000];
string c;
int cx[10000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i] >>c[i];
	}
	if(n==1){
		cout <<0;
	}
	if(n==2){
		cx[1]=c[1]-'0';
		cx[2]=c[2]-'0'; 
		if(cx[1] != cx[2]){
			if(a[1]>a[2]){
				int ans=a[1]-a[2];
				cout <<ans;
			}
			if(a[2]>a[1]){
				int ans=a[2]-a[1];
				cout <<ans;
			}
			if(a[2]==a[1]){
				cout <<0;
			}
		}else{
			cout <<0;
		}
	}
	return 0; 
}
