#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a[10],b[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				cout<<0<<0<<0;
				return 0;	
			}
			if(i==1){
				cout<<1;
				if(s1[i+1]>='D'&&s2[i+1]>='D'||s1[i+1]<='C'&&s2[i+1]<='C'){
					cout<<1;
					if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)cout<<1;
					else cout<<0;
					return 0;
				}
				else{
					cout<<0<<0;
					return 0;
				}	
			}
		}
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;	
	}
	return 0;
}
