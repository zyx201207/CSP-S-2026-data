#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
int a,b;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<f1<<f2<<f3<<f4;
		return 0;
	}else{
		f1=1;
		for(int i=1;i<=s1.size();i++){
			if(s1[i]<='Z'&&s1[i]>='A'){
				c=s1[i];
			}else{
				a=a*10+(int)(s1[i]-'0');
			}
		}
		for(int i=1;i<=s2.size();i++){
			if(s2[i]<='Z'&&s2[i]>='A'){
				d=s2[i];
			}else{
				b=b*10+(int)(s2[i]-'0');
			}
		}
		if(a!=b){
			cout<<f1<<f2<<f3<<f4;
			return 0;
		}else{
			f2=1;
			if(c>='D'&&c<='F'&&d>='D'&&d<='F'){
				f3=f4=1;
			}
			else if(c>='A'&&c<='C'&&d>='A'&&d<='C'){
				f3=1;
				if(c+1==d||d+1==c)f4=1;
			}
		    cout<<f1<<f2<<f3<<f4;
		    return 0;
		}
	}
}
