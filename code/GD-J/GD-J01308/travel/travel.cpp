#include <iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int q,e;
	string w,r;
	cin>>q>>w>>e>>r;
	bool a=1,b=1,c=1,d=1,h;
	if(q!=e)a=b=c=d=0;
	else{
		int u=int(w[0]-'0')*10+int(w[1]-'0'),o=int(r[0]-'0')*10+int(r[1]-'0');
		if(u!=o)
			b=c=d=0;
		else{
			char n=w[2],m=r[2];
			if((n>'C'&&m>'C')||(n<'D'&&m<'D')){
				if(n>'C')
					h=0;
				else if(int(n-m)==1 || int(n-m)==-1)
					h=0;
				else
					d=0;
			}else
				c=d=0;
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
