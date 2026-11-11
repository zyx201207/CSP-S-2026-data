#include<iostream>
using namespace std;
int main () {
	freopen("sting.in","r"stdin);
	freopen("string.out","w"stdout);
	string hw;
	string h;
	string w;
	long long a;
	cin>>a;
	for(int i=0; i<a; i++) {
		long long b;
		char c;
		cin>>b>>c;
		for(int j=0; j<b; j++) {
			hw=hw+c;

		}
	}
	for(int i=0; i<hw.size()/2; i++) {
		h=h+hw[i];
	}
	long long q=hw.size();
	long long t=0;
	if(hw.size()%2==0) {
		for(int i=hw.size()/2; i<hw.size(); i++) {
			w=w+hw[i];
		}
		for(int i=0;i<hw.size()/2;i++){
			if(h[i]!=w[q]){
				t=t+1;
				
			}
			q=q-1;
			
		}
	} else {
		for(int i=hw.size()/2+1; i<hw.size(); i++) {
			w=w+hw[i];
		}
		for(int i=0;i<hw.size()/2;i++){
			if(h[i]!=w[q]){
				t=t+1;
				
			}
			q=q-1;
			
		}
	}
	cout<<t;
	return 0;
}
