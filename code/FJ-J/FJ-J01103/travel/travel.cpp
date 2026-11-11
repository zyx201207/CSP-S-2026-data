#include<iostream>
using namespace std;

namespace lyh{
	
	string a,b,x,y;
	
	void inlyh(){
		cin>>a>>b>>x>>y;
		return;
	}
	
	void solyh(){
		cout<<(a == x)<<((a == x) && (b.substr(0,2) == y.substr(0,2)))<<((a == x) && (b.substr(0,2) == y.substr(0,2)) && ((b[2] < 'D') == (y[2] < 'D')))<<((a == x) && (b.substr(0,2) == y.substr(0,2)) && ((b[2] < 'D') == (y[2] < 'D')) && (abs(b[2] - y[2]) == 1));
		return;
	}
	
	void lyh(){
		inlyh();
		solyh();
		return;
	}
	
	void fre(){
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
		return;
	}
	
}

int main(){
	lyh::fre();
	lyh::lyh();
	return 0;
}
