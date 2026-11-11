#include<bits/stdc++.h>
using namespace std;
int n,a[100000000],c[100000000],l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    if(n<1){
    	cout<<"0";
    	return 0;
	}
	if(n=1){
		cin>>a[1]>>c[1];
		cout<<"0";
		return 0;
	}
	if(n=2){
        	for(int i=0;i<2;i++){
        		cin>>a[i]>>c[i];
			}
		}
		a[1]-=a[2];
		cout<<a[1];
		return 0;
}

