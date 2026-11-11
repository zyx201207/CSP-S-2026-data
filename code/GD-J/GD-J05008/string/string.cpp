#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	string c;
    for(int i=0;i<n;i++){
    	cin>>a;
	}
	for(int i=0;i<n;i++){
		cin>>c;
	}
	for(int i=0;i<c.size();i++){
		for(int j=c.size();j>=0;j--){
		    if(i!=j){
		    	cout<<2;
			}	
		}
	}
	cout<<0;
	return 0;
}
