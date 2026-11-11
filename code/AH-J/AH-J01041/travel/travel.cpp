#include<bits/stdc++.h>
using namespace std;
typedef string s;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	s c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	ll a1=0;
	if(c1==c2){
		a1+=1000;
		ll a=ll(s1[0]-'0')*10+(s1[1]-'0');
		ll b=ll(s2[0]-'0')*10+(s2[1]-'0');
		if(a==b){
			a1+=100;
			char c=s1[2],d=s2[2];
			if(c>='A'&&c<='C'){
				if(d>='A'&&d<='C'){
					a1+=10;
					if((c>d&&d==c-1)||(c<d&&c==d-1)){
						a1+=1;
					}
				}
			}else if(c=='D'||c=='F'){
				if(d=='D'||d=='F'){
					a1+=10;
					a1+=1;
				}
			}
		}
	}
	if(a1==0){
		cout<<"0000";
	}else cout<<a1;
	return 0;
}
