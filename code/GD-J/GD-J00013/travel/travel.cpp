#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[300];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a['A']=a['B']=a['C']=1;
	a['D']=a['F']=2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(a[s1[2]]==a[s2[2]]){
				cout<<1;
				if(a[s1[2]]==2)cout<<1;
				else{
					if(abs(int(s1[2])-int(s2[2]))==1)cout<<1;
					else cout<<0;
				}
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
}
