#include<bits\stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int i=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char a1=s1[2],a2=s2[2];
	if(c1==c2){
		cout<<1;i++;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;i++;
			if(a1+a2<=133||a1+a2==137){
				cout<<1;i++;
				if(abs(a1-a2)==1&&((a1!='C'&&a2!='D')||(a1!='D'&&a2!='C'))){
					cout<<1;i++;
				}
			}
		}
	}
	for(int k=4-i;k>0;k--){
		cout<<0;
	}
	return 0;
}
