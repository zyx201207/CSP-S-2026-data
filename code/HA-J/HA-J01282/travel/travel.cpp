#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c,s,n=0;
	string a,b;
	cin>>c>>a>>s>>b;
	if(c==s&&c>01&&c<16&&s>01&&s<16){
		cout<<n+1;
	}
	else{
		cout<<0;
	}
	if(a==b){
		cout<<n+1;
	}
	else{
		cout<<n+0;
	}
	if((a=="A"||a=="B"||a=="C")&&(b=="A"||b=="B"||b=="C")){
		cout<<n+1;
	}
	else{
		cout<<n+0;
	}
	cout<<n+1;
	return 0;
}
