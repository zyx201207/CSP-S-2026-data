#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2,x,y;
	char k1,k2;
	cin>>c1>>s1>>k1>>c2>>s2>>k2;
	string p="ABCDF";
	for(int i=0;i<5;i++){
		if(k1==p[i]) x=i;
		if(k2==p[i]) y=i;
	}
	
	int a[4]={-1,-1,-1,-1};
	if(c1==c2) a[0]=1;
	else{
		for(int i=0;i<4;i++) a[i]=0;
	}
	if(a[1]!=-1) {
		for(int i=0;i<4;i++) cout<<a[i];
		return 0;
	}
	else {
		if(s1==s2) a[1]=1;
		else{
		    for(int i=1;i<4;i++) a[i]=0;
	    }
	}
	
	if(a[2]!=-1) {
		for(int i=0;i<4;i++) cout<<a[i];
		return 0;
	}
	else {
		if((x<=2&&y<=2)||(x>=3&&y>=3)) a[2]=1;
		else{
		    for(int i=2;i<4;i++) a[i]=0;
	    }
	}
	
	if(a[3]!=-1) {
		for(int i=0;i<4;i++) cout<<a[i];
		return 0;
	}
	else {
		if(abs(x-y)==1) a[3]=1;
	    else a[3]=0;
	}
	
	for(int i=0;i<4;i++) cout<<a[i];
	
	return 0;
} 
