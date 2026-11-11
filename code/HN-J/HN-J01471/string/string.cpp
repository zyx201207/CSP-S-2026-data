#include<iostream>
using namespace std;
char a[1111];
int main(){
	freopen("string.in","r",stdin);
	feropen("string.out","w",stdout);
	long long b;
	cin>>b;
	long long s=0;
	for(int i=1;i<=b;i++){
		cin>>a[i];
		if(a[b-1]==a[i]){
			cout<<"0";
			return 0;
		}else{
			if(a[b-1]!=a[i]){
				s+=1;
			}
		}
	}
	cout<<s;
	return 0;
}
