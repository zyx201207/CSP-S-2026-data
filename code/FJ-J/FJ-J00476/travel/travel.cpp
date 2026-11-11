#include<iostream>
#include<cstdio>
using namespace std;
string a,b,c,d;
int main(){
	
	cin>>a>>b>>c>>d;
	int s[2],j[2];
	s[1]=a[0]-'0';
	s[2]=a[1]-'0';
	j[1]=a[0]-'0';
	j[2]=a[1]-'0';
	if(s[1]==j[1]&&s[2]==j[2])cout<<1;
	else {cout<<"0000";
	return 0;
	}
	int k[3],l[3];
	k[1]=b[0]-'0';
	k[2]=b[1]-'0';
	k[3]=b[2]-'0';
	l[1]=d[0]-'0';
	l[2]=d[1]-'0';
	l[3]=d[2]-'0';
	if(k[2]==l[2])cout<<1;
	else{ cout<<"000";
	return 0;
	}
	int t=1;

	if((k[3]==17||k[3]==18||k[3]==19))t=1;
	else{t=0;
	
	}
		if((l[3]==17||l[3]==18||l[3]==19))t=1;
	else{t=0;
	
	}
	if(t==1)cout<<1;
	else {cout<<"00";
	return 0;
	}
	if(k[3]+1==l[3]||k[3]-1==l[3])cout<<1;
	else cout<<0;
	return 0;
}
