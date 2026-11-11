#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	char a[2],b[2];
	for(int i=0;i<2;i++){
		a[i]=s1[i];
		b[i]=s2[i];
	}
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char c=s1[2],d=s2[2];
	if((c=='D'&&d=='F')||(c=='F'&&d=='D')){
		cout<<11;
	}else if(c!='D'&&c!='F'&&d!='D'&&d!='F'){
		cout<<1;
		if((c+1==d&&c!='C')||(c-1==d&&c!='A')){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<"00";
	}
	return 0;
}
