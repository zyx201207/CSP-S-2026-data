#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[3],s1[4],c2[3],s2[4];
	char a[5]={'0','0','0','0'};
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1==c2){
		a[0]+=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a[1]='1';
			if(s1[2]<='C' && s2[2]<='C' && s1[2]>='D' && s2[2]>='D'){
				a[2]='1';
				if(s1[2]==s2[2]+1||s1[2]==s2[2]-1)a[3]='1';
			}
		}
	}
	for(int i=0;i<=3;i++)cout<<a[i];
	return 0;
}
