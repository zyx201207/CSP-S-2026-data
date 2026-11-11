#include<bits/stdc++.h>
using namespace std;
long long a,ans,tp=1;
long long b0[200005];
char b1[200005];
string tmp;
string fun(int len){
	string temp_;
	for(int i=len-1;i>=0;i--){
		temp_=temp_+tmp[i];
	}
	return temp_;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++){
		cin>>b0[i]>>b1[i];
	}
	bool c=true;
	for(int i=1;i<a;i++){
		if(b0[i-1]!=b0[i]){
			c=false;
			break;
		}
	}
	if(c==true){
		tp=b0[0];
		for(int i=0;i<a;i++){
		    tmp=tmp+b1[i];
	    }
	}
	else{
		for(int i=0;i<a;i++){
			for(int f=0;f<b0[i];f++){
				tmp=tmp+b1[i];
			}
		}
	}
	int len=tmp.length();
	if(fun(len)==tmp){
		cout<<0<<endl;
		return 0;
	}
	else{
		string c=fun(len);
		long long temp_=0;
		for(int i=0;i<len/2;i++){
			if(tmp[i]==c[i]){
				temp_++;
			}
		}
		for(int i=0;i<len/2-(temp_*tp);i++){
			ans++;
		}
		cout<<ans<<endl;
	}
    return 0;
}
