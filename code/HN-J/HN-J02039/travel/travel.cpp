#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,q,p,j,l;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		for(int i=0;i<3;i++){
			if(s1[i]>='0'&&s1[i]<='9'){
				q+=s1[i];
			}
			if(s2[i]>='0'&&s2[i]<='9'){
				p+=s2[i];
			}
		}
		if(q==p){
			cout<<"1";
			for(int i=0;i<3;i++) {
				if(s1[i]>='A'&&s1[i]<='F'){
				j=s1[i];
			}
			
			if(s2[i]>='A'&&s2[i]<='Z'){
				l=s2[i];
			}
		}
			
}
			
			
		
	}else{
		cout<<"0000";
	}
	if(j=="A"){
		if(l=="B"){
			cout<<"11";
		} else if(l=="C") {
			cout<<"10";
		}else{
			cout<<"00";
		}
	}else if(j=="B"){
		if(l=="A"){
			cout<<"11";
		}else if(l=="C"){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}else if(j=="C"){
		if(l=="B"){
			cout<<"11";
		} else if(l=="A") {
			cout<<"10";
		}else{
			cout<<"00";
		}
	}else if(j=="D"){
		if(l=="F"){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}else{
		if(l=="D"){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}
	return 0;
}
