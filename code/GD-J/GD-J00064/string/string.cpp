#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string x;
	cin>>x;
	for(int i=0;i<=x.length();i++){
		if(x[i]=x[i+i-1]){
			cout<<0;
		}else{
			x[i]=x[i+i-1];
			cnt++;
		}
		
	}
	cout<<cnt;
	return 0;
}
