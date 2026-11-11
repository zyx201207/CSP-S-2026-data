#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		return 0; 
	}else{
		cout<<1;
		int t=0,t1=0;
		int i=0;
		while(s1[i]>='0'&&s1[i]<='9'){
			t=t*10+s1[i]-'0';
			i++;
		}
		i=0;
		while(s2[i]>='0'&&s2[i]<='9'){
			t1=t1*10+s2[i]-'0';
			i++;
		}
		if(t!=t1) {
			cout<<0<<0<<0;
			return 0;
		}else{
			cout<<1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else {
				cout<<0<<0;
				return 0;
			}
		}
	}
	return 0;
}
