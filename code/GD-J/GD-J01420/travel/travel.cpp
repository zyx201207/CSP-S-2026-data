#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int f1=0,f2=0,f3=0,f4=0;
	int n=s1.size(),n2=s2.size();
	cin>>c1>>s1>>c2>>s2;
	char l1=s1[n-1];
	char l2=s2[n2-1];
	if(c1!=c2){//是否在一个车厢 
		cout<<"0000";
		return 0;//不在 
	}
	else if(c1==c2){
		f1=1;
		//是否在同一排 
		if((s1[0]!=s2[0])||(s1[1]!=s2[1])){
			f2=0;
		}
		else{//是
			f2=1;
			if((s1[n-1]<='C'&&s2[n2-1]>'C')||(s2[n2-1]<='C'&&s1[n-1]>'C')){
				f3=0;
			}
			else{
				f3=1;
				if((s1[n-1]!=s2[n2-1])&&max(s1[n-1]-'0',s2[n2-1]-'0')-min(s1[n-1]-'0',s2[n2-1]-'0')==1){
					f4=1;
				}else{
					f4=0;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
