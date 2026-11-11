#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,aa,bb;
bool fa,fb;
bool cc(string x,string y){
	if(x[0]==y[0]&&x[1]==y[1])return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a>>aa>>b>>bb;
    if(a==b){
    	cout<<1;
    	if(cc(aa,bb)){
    		cout<<1;
    		if(aa[2]=='A'||aa[2]=='B'||aa[2]=='C'){
    			fa=true;
			}
			if(bb[2]=='A'||bb[2]=='B'||bb[2]=='C'){
    			fb=true;
			}
			if(aa[2]=='D'||aa[2]=='F'){
    			fa=false;
			}
			if(bb[2]=='D'||bb[2]=='F'){
    			fb=false;
			}
			if(fa==fb){
				cout<<1;
				if(fa==1){
					if(abs(aa[2]-bb[2])==1){
						cout<<1;
					}else cout<<0;
				}
				if(fa==0){
					if(abs(aa[2]-bb[2])==2){
						cout<<1;
					}else cout<<0;
				}
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
