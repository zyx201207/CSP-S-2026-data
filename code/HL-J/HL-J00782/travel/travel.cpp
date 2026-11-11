#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n1,n2,c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	for(int i=1;i<=1;i++){
		if(s1[i]>='a'&&s1[i]<='z'){
			s1+=n1;
		}
		if(s2[i]>='a'&&s2[i]<='z'){
			s2+=n2;
		}
		if(n1==n2){
			cout<<1;
			break;
		}else{
			cout<<0;
			break;
		}
		
	}
	return 0;
}