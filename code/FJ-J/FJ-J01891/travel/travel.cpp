#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1;
	string s1;
	char c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	string kkk;
	
	if(c1==c2){
	kkk[0]='1';
	}else{
	kkk[0]='0';
	}
	
	if(kkk[0]='1'){
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
	kkk[1]='1';
	}else{
	kkk[1]='0';
	}
    }else{
	kkk[1]='0';
    }
    int w=0;
	if(s1[2]=s2[2]+1){w=1;}
	if(s1[2]=s2[2]-1){w=1;}
	if(s1[2]='F'){
	if(s2[2]=='D'){
	w=1;	
	}
    }
	if(s1[2]='D'){
	if(s2[2]=='F'){
	w=1;	
	}
    }
	if(kkk[1]=='1'&&w==1){
	kkk[2]='1';
	}else{
	kkk[2]='0';
	}	
	
	int p=0;
	if(s1[2]='F'){
	if(s2[2]=='D'){
	p=1;	
	}
    }
	if(s1[2]='D'){
	if(s2[2]=='F'){
	p=1;	
	}
    }
	if(s1[2]='C'){
	if(s2[2]=='B'){
	p=1;	
	}
    }
	if(s1[2]='B'){
	if(s2[2]=='C'){
	p=1;	
	}
    }
	if(s1[2]='B'){
	if(s2[2]=='A'){
	p=1;
    }
	}
	if(s1[2]='A'){
	if(s2[2]=='B'){
	p=1;	
	}
    }
	if(kkk[2]=='1'&&p==1){
	kkk[3]='1';
	}else{
	kkk[3]='0';
	}	
	
	cout<< kkk<<endl;
	return 0;
}