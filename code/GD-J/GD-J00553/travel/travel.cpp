#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x1,x2,x3,x4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<x1<<x2<<x3<<x4; 
		return 0;
	}
	if(a==c){
		x1=1;
		int m;
		int n;
		m=(b[0]-'0')*10+(b[1]-'0');
		n=(d[0]-'0')*10+(d[1]-'0');
		if(m==n){
			x2=1;
			char p=b[2];
			char q=d[2];
			int w1=int(p);
			int w2=int(q);
			if((w1<=67&&w2<=67)||(w1>=68&&w2>=68)){
				x3=1;
				if(abs(w1-w2)==1){
					x4=1;
				}
			}
		}
	}
	cout<<x1<<x2<<x3<<x4; 
	return 0;
}
