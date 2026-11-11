#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int n[4];
	for(int i=3;i>=0;i--){
    	n[i]=0;
	}
	if(c1==c2){
		n[0]++;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			n[1]++;
			if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'){
				n[2]++;
				if((s1[2]+1)==s2[2]){
					n[3]++;
				}else if((s2[2]+1)==s1[2]){
					n[3]++;
				}
			}else if(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D'){
				n[2]++;
				n[3]++;
			}
		}
    }
    for(int i=0;i<4;i++){
    	cout<<n[i];
	}
	return 0;
} 
