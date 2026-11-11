#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string s1,s2;
	char m=s1[2];
	char p=s2[2];
	char x=s1[0],y=s1[1],z=s2[1],w=s2[0];
	char c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(((p>='A')&&(p<='F')&&(p!='E')&&(m>='A')&&(m<='F')&&(m!='E'))&&((c1=='17'||c2=='17')||(c1>='02'&&c1<='15')||(c1>='02'&&c1<='15'))){
		if(c1==c2=='17'){
    		if((x==w)&&(y==z)){
    			if(((p=='A')&&(m=='B'))||((p=='C')&&(m=='B'))||((p=='B')&&(m=='C'))||((p=='D')&&(m=='F'))||((p=='F')&&(m=='D'))){
    		    		cout<<1111;
			     	}else if(((p=='A')&&(m=='C'))||((p=='C')&&(m=='A'))){
					    cout<<1110;
			        }else if(((p=='A'||p=='B'||p=='C')&&(m=='D'||m=='F'))||((m=='A'||m=='B'||m=='C')&&(p=='D'||p=='F'))){
					cout<<1100;
			        }	
			    }else {
				cout<<1000;
			}
		}else{
			cout<<0000;
		}
    }
	return 0;
}
