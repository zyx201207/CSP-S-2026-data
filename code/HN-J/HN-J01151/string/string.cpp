#include<iostream>
#include<algorithm> 
using namespace std;
int n;
long long a1,a2,shu[200008];
char b,b2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==2){
		cin>>a1>>b;
		cin>>a2>>b2;
		if(b!=b2) cout<<min(a1,a2);
		else cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a1>>shu[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	} 

	return 0;
	
	
}
