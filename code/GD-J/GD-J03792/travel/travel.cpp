#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a[5]={};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[1]=1;
		if(s1[1]==s2[1] && s1[0]==s1[0]){
			a[2]=1;
			if(('A'<=s1[2] && s1[2]<='C' && 'A'<=s2[2] && s2[2]<='C') || ('D'<=s1[2] && s1[2]<='F' && 'D'<=s2[2] && s2[2]<='F')){
				a[3]=1;
				if(abs(s1[2]-s2[2])==1){
					a[4]=1;
				}
			}
		}
	}
//	cout<<s1[2]<<' '<<s2[2]<<endl;
//	cout<<('A'<=s1[2]<='C' && 'A'<=s2[2]<='C')<<endl;
	for(int i=1;i<=4;i++) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
