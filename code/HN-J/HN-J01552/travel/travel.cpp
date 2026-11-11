#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char c=s1[2],cc=s2[2];
	int a1=c-'A',a2=cc-'A';
	if(a1>a2){
		swap(a1,a2);
	}
	if(a1==0&&a2==1){
		cout<<"11";
		return 0;
	}
	if(a1==0&&a2==2){
		cout<<"10";
		return 0;
	}
	if(a1==0&&a2==3){
		cout<<"00";
		return 0;
	}
	if(a1==0&&a2==5){
		cout<<"00";
		return 0;
	}
	if(a1==1&&a2==2){
		cout<<"11";
		return 0;
	}
	if(a1==1&&a2==3){
		cout<<"00";
		return 0;
	}
	if(a1==1&&a2==5){
		cout<<"00";
		return 0;
	}
	if(a1==2){
		cout<<"00";
		return 0;
	}
	if(a1==3&&a2==5){
		cout<<"11";
		return 0;
	}
	return 0;
}
