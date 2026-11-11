#include<bits/stdc++.h>
using namespace std;
string c,cc,s,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c[0]!=cc[0] || c[1]!=cc[1]){//是否为同一车厢 
		cout<<"0000";
		return 0;
	}
	else{//是同一车厢
		cout<<"1";//1
		if(s[0]!=ss[0] || s[1]!=ss[1]){//是否为同一排 
			cout<<"000";
			return 0;
		}
		else{//是同一排
			cout<<"1";//2
			if(s[2]=='A' || s[2]=='B' || s[2]=='C'){//是否为同一侧 1
			    //cout<<"#";
			    if(ss[2]=='D' || ss[2]=='F' || ss[2]==s[2]){
			    	cout<<"00";
			    	return  0;
				}
				else{//是同一侧 
					cout<<"1";//3
					//是否相邻 
					if(s[2]=='A' && ss[2]=='B'){
						cout<<"1";//4
						return 0;
					}
					else if(s[2]=='B' && (ss[2]=='A' || ss[2]=='C')){
						cout<<"1";//4
						return 0;
					}
					else if(s[2]=='C' && ss[2]=='B'){
						cout<<"1";//4
						return 0;
					}
					else{//不相邻 
						cout<<"0";
					}
				}
			}
			
			else if(s[2]=='D' || s[2]=='F'){//是否为同一侧 2
			    if(ss[2]=='A' || ss[2]=='B' || ss[2]=='C' || ss[2]==s[2]){
			    	cout<<"00";
			    	return  0;
				}
				else{//是同一侧  此侧只有两个座位，已经构成相邻 
					cout<<"11";
					return 0;
				}
			}
			return 0;
		}
	}
	return 0;
}
