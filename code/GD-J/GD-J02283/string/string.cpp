#include<bits/stdc++.h>
using namespace std;
int a[10005];
char c1[10005],c2[10005];
string s;
int main(){
	int n;
	cin>>n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c1[i];
		cin>>c2[i];	
		if(n==1){
			cout<<0;
		}
		if(n==2){
			if(c1[i]==-c2[i]){
				cout<<0;
			} 
			else{
				cout<<1;
			}
		}
	}
	return 0;
}
