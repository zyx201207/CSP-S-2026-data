#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int p,q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>c>>b>>d;
	p=(c[0]-'0')*10+(c[1]-'0');
	q=(d[0]-'0')*10+(d[1]-'0');
//	cout<<p<<" "<<q<<endl;
	int s1=c[2]-'A'+1,s2=d[2]-'A'+1;
//	cout<<s1<<" "<<s2<<" "<<(c[2]-d[2])+10<<" "<<endl;
	if(a!=b){
		cout<<"0000";
		return 0;
	}else if(p!=q){
		cout<<"1000";
		return 0;
	}else if((s1<=3&&s2>3)||(s1<=3&&s2>3)){
		cout<<"1100";
		return 0;
	}else if((c[2]-d[2])+10==9){
		cout<<"1111";
		return 0;
	}else if((c[2]-d[2])+10==11){
		cout<<"1111";
		return 0;
	}else{
		cout<<"1110";
	}
} 
