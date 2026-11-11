#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string s1,s2,s3,s4;
cin>>s1>>s2>>s3>>s4;
int e1=1,e2=1,e3=1,e4=1;
if(s1!=s3) e1=0;
int len=s2.size();
int len2=s4.size();
if(e1!=0){
	

	for(int i=0;i<len;i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			if(s2[i]!=s4[i]){
				e2=0;
			}
		}else if(e2!=0){
			if(s2[len-1]='A'){
				if(s4[len-1]=='D'){
					e3=0;
					e4=0;
				} 
				if(s4[len-1]=='F'){
					e3=0;
					e4=0;
				}
				
			}
			if(s2[len-1]='B'){
				if(s4[len-1]=='D'){
					e3=0;
					e4=0;
				} 
				if(s4[len-1]=='F'){
					e3=0;
					e4=0;
				}
			}
			if(s2[len-1]='C'){
				if(s4[len-1]=='D'){
					e3=0;
					e4=0;
				} 
				if(s4[len-1]=='F'){
					e3=0;
					e4=0;
				}
			}
			if(s2[len-1]='D'){
				if(s4[len-1]!='D'){
					e3=0;
					e4=0;
				} 
				if(s4[len-1]!='F'){
					e3=0;
					e4=0;
				}
			}
			if(s2[len-1]='F'){
				if(s4[len-1]!='D'){
					e3=0;
					e4=0;
				} 
				if(s4[len-1]!='F'){
					e3=0;
					e4=0;
				}
			}
			
		}else{
			e2=e3=e4=0;
		}
		
	}
}else{
	e1=e2=e3=e4=0;
}
printf("%d%d%d%d\n",e1,e2,e3,e4);
	return 0;
}
