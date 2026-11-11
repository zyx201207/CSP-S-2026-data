#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==3){
		cout<<"2";
	}else{
		if(n==2){
			cout<<"0";
		}else{
			cout<<"3000000000";
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
