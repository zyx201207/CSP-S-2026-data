#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);
	string c1,c2;
	int s1,s2;
	char s3,s4;
	int h=0,h1=0,h2=0,h3=0;
	cin>>c1>>s1>>s3>>c2>>s2>>s4;
	if(c1==c2){
		h+=1;
		if(s1==s2){
			h1+=1;
			if('s3'+1=='s4'){
				h2+=1;
				h3+=1;
				if('s3'-1=='s4'){
					h2+=1;
					h3+=1;
				}
			}else{
				cout<<h<<h1<<h2<<h3;
				return 0;
			}
	    }else{
		    cout<<h<<h1<<h2<<h3;
		    return 0;
	    }
	}else{
		cout<<h<<h1<<h2<<h3;
		return 0;
	}
	cout<<h<<h1<<h2<<h3;
	return 0;
} 
