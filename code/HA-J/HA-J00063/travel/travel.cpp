#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(read,"travel.in","r");
	freopen("travel.ans","w");
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool is1=0,is2=0,is3=0;
	int a=(c1[0]-'0')*10+c1[1]-'0',b=(c2[0]-'0')*10+c2[1]-'0';
	int c=(s1[0]-'0')*10+s1[1]-'0',d=(s2[0]-'0')*10+s2[1]-'0';
	if(a==b){
		cout<<"1";
		if(c==d){
			is1=1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				is2=1;
				if(abs(s1[2]-s2[2])==1)is3=1;
			}
		}
		
	}
	else cout<<"0";
	cout<<is1<<is2<<is3;
	return 0; 
}
