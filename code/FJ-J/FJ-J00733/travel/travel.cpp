#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int n=c1.size();
	for(int i=0;i<n;i++){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}
	} cout<<'1';
	int m=s1.size();
	for(int i=0;i<m-1;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		}
	} cout<<1;
	if((s1[2]>='D'&&s2[2]<='C')||(s2[2]>='D'&&s1[2]<='C')){
		cout<<"00";
		return 0;
	}else cout<<1;
	if((s1[2]+1==s2[2])||s2[2]+1==s1[2]){
		cout<<1;
	}else cout<<0;
	return 0;
} 
//hello~~~~~
