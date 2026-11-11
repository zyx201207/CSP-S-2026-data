#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int A[4]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		A[0]=1;
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			A[1]=1;
			if((s1[2]+s2[2]=='F'+'D')or(s1[2]+s2[2]=='A'+'B')or(s1[2]+s2[2]=='B'+'C')or(s1[2]+s2[2]=='A'+'C')){
				A[2]=1;
				if(s1[2]-s2[2]==1 or s2[2]-s1[2]==1){
					A[3]=1;
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<A[i];
	}
	cout<<endl;
	return 0;
} 
