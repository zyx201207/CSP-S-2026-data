//GZ-J00204 ∫Î“„÷–—ß —Ó •Ω‹ 
#include<bits/stdc++.h>
using namespace std; 
string c1,s1,c2,s2;
int a[4]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[0]=1;
		if((s1[0]==s2[0])&&(s1[1]==s2[1])){
			a[1]=1;
			if((s1[2]>'C'&&s2[2]>'C')||(s1[2]<='C'&&s2[2]<='C')){
				a[2]=1;
				if(abs(s1[2]-s2[2])==1){
					a[3]=1;
				}
				else{
					a[3]=0;
				}
			}
			else{
				a[2]=0;
				a[3]=0;
			}
		}
		else{
			a[1]=0;
			a[2]=0;
			a[3]=0;
		}
	}else{
		a[0]=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}
