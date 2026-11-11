#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int a_=0,b_=0,c_=0,d_=0;
	cin>>a>>b>>c>>d;
		if(a==c){
			a_++;
		}
		if(b==d){
			b_++;
			c_++;
			d_++;
			
		}
	cout<<a_<<b_<<c_<<d_;
	return 0;
}
