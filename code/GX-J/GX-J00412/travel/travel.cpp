#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,len,len1;
char c,d;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	len=a.size();
	len1=b.size();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			x=x*10+a[i]-'0';
		}
		else c=a[i];
	}
	for(int i=0;i<len1;i++){
		if(b[i]>='0'&&b[i]<='9'){
			y=y*10+b[i]-'0';
		}
		else d=b[i];
	}
	if(n!=m) cout<<"0000";
	else{
		if(x==y){
			if((c=='D'&&d=='F')||(c=='F'&&d=='D')){
				cout<<"1111";
			}
			else if((c=='A'&&d=='B')||(c=='B'&&d=='A')||(c=='B'&&d=='C')||(c=='C'&&d=='B')){
				cout<<"1111";
			}
			else if((c=='A'&&d=='C')||(c=='C'&&d=='A')){
				cout<<"1110";
			}
			else cout<<"1100";
		}
		else{
			cout<<"1000";
		}
	}
return 0;
}
