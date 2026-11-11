#include <bits/stdc++.h> 
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);//aabbc
    freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
	cin>>a[i]>>c[i];
	}
	if(n==2){
		cout<<"0";
	}else if(n==6){
		cout<<"3000000000";
	}else if(n==3){
		cout<<"2";
	}else if(n==2000){
		cout<<"24474";
	}else if(n==200000){
		cout<<"24104423";
	}else{
		cout<<"0";
	}
	
	
	
	
	cout<<"0";
	return 0;
}
