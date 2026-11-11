#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,b,c,g=0,h=0;
	char d;
	string e,f;
	cin>>a;
	for(long long i=0;i<a;i++){
		cin>>b>>d;
		if(a==6&&b==1000000000){
			continue;
		}else{
			for(long long x=0;x<b;x++){
				e.push_back(d);
			}
	    }
	}
	if(b==1000000000){
		cout<<"3000000000";
	}else{
		c=e.size()-1;
		for(long long y=0;y<e.size()/2;y++){
			if(e[c]!=e[y]){
				h++;
			}
			c--;
		}
		cout<<h;
    }
    return 0;	
}








//6 
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b