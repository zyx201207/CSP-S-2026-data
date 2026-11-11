#include<bits/stdc++.h>
using namespace std;
int n,num,num1;
char c,c1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n;
    if(n==1){
    	cout<<0;
    	return 0;
	}
	if(n==2){
		cin>>num>>c>>num1>>c1;
		cout<<min(num,num1);
	}
    for(int i=1;i<=n;i++){
    	cin>>num>>c;
	}
	return 0;
}
