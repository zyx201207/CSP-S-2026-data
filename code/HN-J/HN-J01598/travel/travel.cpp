#include <bits/stdc++.h>
using namespace std;


int a[200005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	
	cin>>c1>>s1>>c2>>s2;

	if(c1==c2) a[0]=1;
	else a[0]=0;
	
	if(s1[0]==s2[0] and s1[1]==s2[1] and a[0]==1){
		a[1]=1;
	}else{
		a[1]=0;
	}
	if(a[1]==1){
		if(s1[s1.size()-1]<='C'){
			if(s2[s2.size()-1]<='C'){
				a[2]=1;
			}else a[2]=0;
		}else{
			if(s2[s2.size()-1]=='D' or s2[s2.size()-1]=='F'){
				a[2]=1;
			}else{
				a[2]=0;
			}
		}
	}else{
		a[2]=0;
	}
	if(a[2]==1){
		if(abs(s1[s1.size()-1]-s2[s2.size()-1]) ==1 or (s1[s1.size()-1]=='D' and s2[s2.size()-1]=='F') or (s1[s1.size()-1]=='F' and s2[s2.size()-1]=='D')){
			a[3]=1;
		}else{
			a[3]=0;
		}
	}else{
		a[3]=0;
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	
	
	
	
	
	return 0;
} 
