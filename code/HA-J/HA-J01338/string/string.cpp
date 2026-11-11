#include <bits/stdc++.h>
using namespace std;
long long n;
long long a;
char c;
string k="";
bool hw(string x){
	string x1={};
	for(int i=2;i<=x.size()+1;i++){
		x1+=x[x.size()+1-i];	
	}
	cout<<x1<<endl;
	if(x1==x){
		return 1;
	}
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a>>c;
    	for(int j=1;j<=a;j++){
    		k+=c;
		}
	}
	if(hw(k)){
		cout<<0;
	}else{
		cout<<1;
	}
	return 0;
}