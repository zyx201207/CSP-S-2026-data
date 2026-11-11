#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[1005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool b=1,b1=1;
	int sum1,sum2;
	for(int i=0;i<c1.size();i++){
		if(c1[i]!=c2[i]){
			cout<<0;
			b=0;
			break;
		}
	}
	if(b){
		cout<<1;
		for(int i=0;i<s1.size()-1;i++){
			if(s1[i]!=s2[i]){
				cout<<0;
				b1=0;
				break;
			}
		}
		if(b1){
			cout<<1;
			if(s1[s1.size()-1]<='C'&&s2[s2.size()-1]<='C') cout<<1;
			else if(s1[s1.size()-1]>'C'&&s2[s2.size()-1]>'C') cout<<1;
			else{
				cout<<0<<0;
				return 0;
			}
			if(s1[s1.size()-1]-1==s2[s2.size()-1]) cout<<1;
			else if(s1[s1.size()-1]==s2[s2.size()-1]-1) cout<<1;
			else cout<<0;
		}
		else cout<<0<<0;
	}
	else cout<<0<<0<<0;
	return 0;
}
