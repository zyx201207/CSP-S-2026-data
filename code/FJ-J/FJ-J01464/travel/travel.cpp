#include<bits/stdc++.h>
using namespace std;
string a,aa,b,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	string p="",q="";
	p=p+aa[0]+aa[1];
	q=q+bb[0]+bb[1];
	aa.erase(0,2);
	bb.erase(0,2);
	int n=aa[0]-'A'+1,m=bb[0]-'A'+1;
//	cout<<p<<' '<<q<<' '<<aa<<' '<<bb;
//	cout<<n<<' '<<m;

	if(a==b){
		cout<<1;
		if(p==q){
			cout<<1;
			if((n>=1&&n<=3&&m>=1&&m<=3)){
				cout<<1;
				if(abs(n-m)==1) cout<<1;
				else cout<<0;
			}if(n>=4&&n<=6&&m>=4&&m<=6){
				cout<<1<<1;
			}else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
//ÎÒÊÇtc 
//8:47
//Ô¤ÆÚ100 
