#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int a[1];
bool f(string x,string y)
{
	for(int i=0;i<=1;i++){
		if(x[i]!=y[i]){
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(s[2]=='A' || s[2]=='B' || s[2]=='C'){
		a[0]=1;
	}
	else{
		a[0]=0;
	}
	if(ss[2]=='A' || ss[2]=='B' || ss[2]=='C'){
		a[1]=1;
	}
	else{
		a[1]=0;
	}
	if(f(c,cc)==true){
		cout<<1;
		if(f(s,ss)){
			cout<<1;
			if(a[0]==a[1]){
				cout<<1;
				if(abs(ss[2]-s[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
		return 0;
	}	

} 
