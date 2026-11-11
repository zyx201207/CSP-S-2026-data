#include<bits/stdc++.h>
using namespace std;
long long a,sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		int n;
		string c;
		cin>>n>>c;
	    string s=c;
		if(s==c){
			sum++;
		}else{
			sum--;
		}
	}
	if(sum==a){
		cout<<0;
		return 0;
	}
	return 0;
}	
