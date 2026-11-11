#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int an,bn,cn,dn,zb,zd;
string num;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<a.size();i++){//a
		if(an==0&&a[i]=='0'){
			an=0;
		}
		else {
			an*=10;
			an+=a[i]-'0';
		}
	}for(int i=0;i<c.size();i++){//c
		if(cn==0&&c[i]=='0'){
			cn=0;
		}
		else {
			cn*=10;
			cn+=c[i]-'0';
		}
	}for(int i=0;i<b.size();i++){//b
		if(bn==0&&b[i]=='0'){
			bn=0;
		}
		else if(b[i]>='0'&&b[i]<='9'){
			bn*=10;
			bn+=b[i]-'0';
		}
		else if(b[i]>='A'&&b[i]<='Z'){
			zb=b[i]-'A';
		}
	}for(int i=0;i<d.size();i++){//b
		if(dn==0&&d[i]=='0'){
			dn=0;
		}
		else if(d[i]>='0'&&d[i]<='9'){
			dn*=10;
			dn+=d[i]-'0';
		}
		else if(d[i]>='A'&&d[i]<='Z'){
			zd=d[i]-'A';
		}
	}
	if(an==cn){//同车 
		num+="1"; 
	}else{
		num+="0";
	}
	if(bn==dn&&num=="1"){//同排 
		num+="1"; 
	}else{
		num+="0";
	}
	if(((zb<=2&&zd<=2)||(zb>=3&&zd>=3))&&num=="11"){//同侧 
		num+="1"; 
	}else{
		num+="0";
	}
	if(abs(zb-zd)==1&&(num=="111")){//一起 
		num+="1"; 
	}else{
		num+="0";
	}
	cout<<num;
	return 0;
}
