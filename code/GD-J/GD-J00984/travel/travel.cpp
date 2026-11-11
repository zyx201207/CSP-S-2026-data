#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	if(c1!=c2){
	    cout<<"0000";
	    return 0;
    }
	int a=s1[2],b=s2[2];
	int c=(s1[0]-'0')*10+s1[1]-'0',d=(s2[0]-'0')*10+s2[1]-'0';
	if(c==d) cout<<1;
	else cout<<0;
	if(c==d&&a<=67&&b<=67||a>=68&&b>=68) cout<<1;
	else cout<<0;
	if(a==67&&b==68||a==68&&b==67) cout<<0;
	else if(c==d&&a-b==1||d==c&&b-a==1){
		cout<<1;
	}
	else if(c-d==1&&a==b||d-c==1&&a==b){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
