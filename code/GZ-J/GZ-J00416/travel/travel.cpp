//GZ-J00416 代正维 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
char c1[2],s1[3],c2[2],s2[3];
long long i;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(i=0;i<2;i++){
		cin>>c1[i];
	}
	for(i=0;i<3;i++){
		cin>>s1[i];
	}
	for(i=0;i<2;i++){
		cin>>c2[i];
	}
	for(i=0;i<3;i++){
		cin>>s2[i];
	}
	int a=s1[2];
	int b=s2[2];
    if((c1[0]==c2[0])&&(c1[1]==c2[1])){
		cout<<1;
		if((s1[0]==s2[0])&&(s1[1]==s2[1])){
			cout<<1;
			if((a<b&&(b<=67||a>=68))||(b<a&&(a<=67||b>=68))){
		    	cout<<1;
				if((a<b&&b-a==1&&b<=67)||(a<b&&b-a==2&&a>=68)||(a>b&&a-b==1&&a<=67)||(a>b&&a-b==2&&b>=68)){
			        cout<<1;
		        } 
				else{
					cout<<0;
				}  
			}
		    else{
		    	cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
