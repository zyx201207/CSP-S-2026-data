#include<bits/stdc++.h>
using namespace std;
long long n;
long long arr[1000005];
int main(){
	freopen("travel.in","r",intin);
	freopen("travel.out","w",intout); 
	int a,c;
	cin>>a>>c;
	string b,d;
	cin>>b>>d;
	if(a==c&&a!=01){
		cout<<"11";
		if(b>d){
			cout<<"11";
		}
		else{
			cout<<"00";
		}
}
	if(a!=c){
		cout<<"00";
		if(b==d){
			cout<<"11";
		}
		else{
			cout<<"00";
		}
}
	return 0;
} 

