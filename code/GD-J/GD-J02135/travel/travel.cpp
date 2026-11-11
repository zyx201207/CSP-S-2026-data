#include <iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int f1=0,f2=0,f3=0,f4=0;
	cin >> a >> b >> c >> d;
	if(a==c){
		f1=1;
		int b1,d1;
		b1=int(b[0])*10+int(b[1]);
		d1=int(d[0])*10+int(d[1]);
		if(b1==d1){
			f2=1;
			if((b[2]<'D'&&d[2]<'D')||(b[2]>='D'&&d[2]>='D')){
				f3=1;
				if(b[2]+1==d[2]||b[2]-1==d[2]){
					f4=1;
				}
			}
		}
	}
	cout << f1 << f2 << f3 << f4;
	return 0;
} 
