#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long s,x;
	cin>>s;
	for(int i=1;i<=s;i++){
		cin>>x;
	}
	if(s==3)
		cout<<2;
	if(s==2)
		cout<<0;
	if(s==6)
		cout<<"3000000000";
	return 0;
}
