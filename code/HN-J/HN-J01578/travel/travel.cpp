#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[]={1,1,1,2,2},f1,f2,f3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f3=1;
			if(a[s1[2]-'A']==a[s2[2]-'A']){
				f1=1;
				if(s1[2]-1==s2[2]||s1[2]==s2[2]-1)f2=1;
			}
		}
	}else cout<<0;
	cout<<f3<<f1<<f2;
	
	return 0;
}
