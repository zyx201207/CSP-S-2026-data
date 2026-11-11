#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a[10];
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]==s2[2]){
		a[1]=0;
		a[2]=0;
		a[3]=0;
		a[4]=0;
		for(int i=1;i<=4;i++){
			cout<<a[i];
		}
		return 0;
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		a[1]=1;
	}else{
		a[1]=0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a[2]=1;
	}else{
		a[2]=0;
	}
	if(c1[0]=='0'&&c1[0]=='1'||c2[0]=='1'&&c2[0]=='6'){
		a[1]=0;
	}
	
	if(a[1]=1){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(s1[2]-s2[2]==1||s1[2]-s2[2]==2||s2[2]-s1[2]==1||s2[2]-s1[2]==2){
				if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='B'&&s2[2]=='D'||s1[2]=='C'&&s2[2]=='F'){
					a[3]=0;
				}else{
					a[3]=1;
				}
			}
		}
	}
	
	if(a[2]==1){
		if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
			a[4]=1;
		}else{
			a[4]=0;
		}
		if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'){
		    a[4]=0;
	    }
    }else{
    	a[4]=0;
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
}
