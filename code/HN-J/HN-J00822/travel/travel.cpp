#include<bits/stdc++.h>
using namespace std;
int s[3],s1[3];
bool f=true,f1=true,f2=false,c[7];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	int la=a.length();
	for(int i=0;i<la;i++){
		s[i+1]=a[i]-48;
		s1[i+1]=b[i]-48;
		if(s[i+1]!=s1[i+1]){
			f=false;
			cout<<0;
			break;
		}
	}
	if(f==true){
		cout<<1;
		for(int i=0;i<la;i++){
			s[i+1]=a1[i]-48;
			s1[i+1]=b1[i]-48;
			if(s[i+1]!=s1[i+1]){
				f1=false;
				cout<<0;
				break;
			}
		}
		if(f1==true){
			cout<<1;
			if((a1[2]>='A'&&a1[2]<='C')&&(b1[2]>='A'&&b1[2]<='C')||(a1[2]>='D'&&a1[2]<='F')&&(b1[2]>='D'&&b1[2]<='F')){
				cout<<1;
				f2=true;
			}
			else cout<<0;
			if(f2==true){
				s[0]=a1[2]-64;
				s1[0]=b1[2]-64;
				c[s[0]]=true;
				c[s1[0]]=true;
				if(c[2]==true||(c[4]==true&&c[6]==true))cout<<1;
				else cout<<0;
			}
			else cout<<0;
		}
		else cout<<0<<0; 
	}
	else cout<<0<<0<<0;
	return 0;
}
