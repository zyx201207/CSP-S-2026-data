#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,c,s=0;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c;
		s+=c;
	}
	if(a==1){
		cout<<c;
	}
	else{
		cout<<s;
	}
	return 0;
}
