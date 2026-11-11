#include <bits/stdc++.h> 
using namespace std;
struct mm{
	string a;
	string b;
};
bool cmp(mm p,mm q){
	string x,y,z,k;
	if(p.a!=q.a){
		x="0";
	}
	else{
		x="1";
		if(p.b[0]!=q.b[0]||p.b[1]!=q.b[1]){
			y="0";
		}
		else{
			y="1";
			if(!((p.b[2]<='C'&&q.b[2]>'C')||(p.b[2]>'C'&&q.b[2]<='C'))){
				z="0";
			}
			else{
				z="1";
				if((p.b[2]=='A'&&q.b[2]=='C')||(p.b[2]=='C'&&q.b[2]=='A')){
					k="0";
				}
				else{
					k="1";
				}
			}
		}
	}
	string m=x+y+z+k;
	return m;
};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	mm l[4];
	cin>>l[0].a>>l[0].b;
	cin>>l[1].a>>l[1].b;
	cout<<sort(l+1,l+2,cmp);
}
