#include "iostream"
using namespace std;
string c1,s1,c2,s2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int n=s1.length();
	int m=s2.length();
	
	if(c1==c2){
	cout<<1;
	if(n!=m){
		cout<<0<<0<<0;
		return 0;
	}
		else if(n==3&&m==3){
			if(s1[0]==s2[0]&&s1[1]==s2[1]){
				cout<<1;
				a=s1[2];
				b=s2[2];
			}
			else cout<<0;
		}
		else if(n==4&&m==4){
			if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]==s2[2]){
				cout<<1;
				a=s1[3];
				b=s2[3];
			}
			else cout<<0;
		}
		if(a&&b){
			if(a>='A'&&a<='C'&&b>='A'&&b<='C'){
				cout<<1;
				if(a<b){
					if(a+1==b)cout<<1;
					else cout<<0;
				}
				else if(a>b){
					if(b+1==a)cout<<1;
					else cout<<0;
				}
			}
			else if(a>='D'&&a<='E'&&b>='D'&&b<='E'){
				cout<<1;
				if(a<b){
					if(a+1==b)cout<<1;
					else cout<<0;
				}
				else if(a>b){
					if(b+1==a)cout<<1;
					else cout<<0;
				}
			}
			else if((a>='D'&&a<='E'&&b>='A'&&b<='C')||(b>='D'&&b<='E'&&a>='A'&&a<='C')){
				cout<<0<<0;
			}
		}
		else cout<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
