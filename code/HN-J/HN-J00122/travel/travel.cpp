#include<iostream>
#include<algorithm>
using namespace std;
bool p(string w,string e){
	for(int i=0;i<w.size()-1;i++){
		if(w[i]!=e[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
		char b1=b[b.size()-1];
		char d1=d[d.size()-1];
		if(p(b,d)){
			cout<<'1';
			if(b1>d1){
				swap(d1,b1);
			}
			if(b1=='D'&&d1=='F'){
				cout<<"11";
			}else if(d1<='C'){
				cout<<'1';
				if(d1==b1+1){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
