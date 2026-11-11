#include<bits/stdc++.h>
using namespace std;
bool abc[27];
int main(){
	freopen("string.in","r",stdin);
	freopen("string out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	int a=0;
	char x;
	int zong=0,zimu=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>x;
		zong+=a;
		if(abc[(int)x-96]==0){
			zimu++;
			abc[(int)x-96]=1;
		}
	}
	if(zimu==1){
		cout<<0<<endl;
	}else{
		cout<<zong/2<<endl;
	}
}
