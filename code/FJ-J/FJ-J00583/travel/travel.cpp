#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin>>a>>b>>c>>d;
	int aa=int(a[0]-48)*10+int(a[1]-48);
	int bb=int(b[0]-48)*10+int(b[1]-48);
	int cc=int(c[0]-48)*10+int(c[1]-48);
	int dd=int(d[0]-48)*10+int(d[1]-48);	
	if(aa==cc){
		cout<<1;
		if(bb==dd){
			cout<<1;
			if((b[2]=='A'&&d[2]=='B')||(b[2]=='A'&&d[2]=='C')||(b[2]=='B'&&d[2]=='C')||(b[2]=='F'&&d[2]=='D')||  (b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')){
				cout<<1;
				if(abs(int(b[2])-int(d[2]))==1){
					if((b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C')){
						cout<<0;
					}else{
						cout<<1;
					}
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	//cin.tie(0);
	//cout.tie(0);
	fclose(stdin);
	fclose(stdout);

	return 0;
}

