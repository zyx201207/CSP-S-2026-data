#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a!=b){
		cout<<"0000";
		return 0;
	}else{
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			cout<<"1000";
			return 0;
		}else{
			int m=-1,n=-1;
			if(s1[2]>'C')m=1;
			if(s2[2]>'C')n=1;
			if(m*n<0){
				cout<<"1100";
				return 0;
			}else{
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}
			}
		}
	}
}
