#include<bits/stdc++.h>
using namespace std;
int n,m,l,f2,f1=0,cnt=0;
string s="";
char c1,c2;
bool c12=true;
int main()
{
	freopen("sting.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>c1;
		if(i==1) c2=c1;
		else{
			if(c2!=c1) c12=false;
			else c12 =true; 
		}
		for(int i=1;i<=m;i++){
			s=s+c1;
		}
	}
	if(c12){
		cout<<0;
	}
	else {
		l=s.size();
		f2=l-1;
		while(f2>f1){
			if(s[f2]!=s[f1]) cnt++;
			f1++;
			f2=f2-1;
		}
	cout<<cnt;
	}
    return 0;
}
