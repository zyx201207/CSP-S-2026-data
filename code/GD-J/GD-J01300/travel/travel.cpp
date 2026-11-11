#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int a[4]={0};
	if(c1==c2){
		a[0]=1;
	}
	int e=0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a[1]=1;
		e=1;
	}
	int w=0;
	if(e&&((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]<='F'&&s2[2]>='D'))){
		w=1;
		a[2]=1;
		
	}
	if(w&&(s1[2]-s2[2]==1||s2[2]-s1[2]==1)){
		a[3]=1;
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	return 0;
}
