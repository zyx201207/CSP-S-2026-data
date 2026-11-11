#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s1>>m>>s2;
	a=(s1[0]-'0')*10+(s1[1]-'0');
	b=(s2[0]-'0')*10+(s2[1]-'0');
	c=s1[2]-'0';
	d=s2[2]-'0';
	if(n==m){
		cout<<1;
		if(a==b){
			cout<<1;
			if(c<=19&&d>19)cout<<"00";
			if(c>19&&d<=19)cout<<"00";
			if(c>19&&d>19)cout<<"11";
			if(c<=19&&d<=19){
				if(c>d){
					if(c-d==1)cout<<"11";
					else cout<<"10";
				}else{
					if(d>c){
						if(d-c==1)cout<<"11";
						else cout<<"10";
					}
				}
			}
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
