#include<bits/stdc++.h>
using namespace std; 
string a[3],s,c[3]; char d[3];
int n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>a[i]>>s;
		for(int j=1;j<=s.size();j++){
			if(s[j]>='1'&&s[j]<='9') c[i]=s[j];
			if(s[j]>='A'&&s[j]<='F') d[i]=s[j];
		}
	}
	if(a[1]==a[2]){
		n++; 
		if(c[1]==c[2]){
			n++;
			if(d[1]=='A'&&d[2]=='B'||d[1]=='C'&&d[2]=='B'||d[1]=='A'&&d[2]=='C'||d[1]=='D'&&d[2]=='F'||d[1]=='B'&&d[2]=='A'||d[1]=='B'&&d[2]=='C'||d[1]=='C'&&d[2]=='A'||d[1]=='F'&&d[2]=='D'){
				n++;
				if(d[1]=='A'&&d[2]=='B'||d[1]=='C'&&d[2]=='B'||d[1]=='D'&&d[2]=='F'||d[1]=='B'&&d[2]=='A'||d[1]=='B'&&d[2]=='C'||d[1]=='F'&&d[2]=='D'){
					n++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<"1";
	}
	for(int i=1;i<=4-n;i++){
		cout<<"0";
	}
	return 0;	
}
