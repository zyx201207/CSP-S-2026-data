#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		int e=int(b[0])*10+int(b[1]);
		int f=int(d[0])*10+int(d[1]);
		if(e==f){
			cout<<1;
			char g=char(b[2]);
			char h=char(d[2]);
			if(((g=='A'||g=='B'||g=='C')&&(h=='A'||h=='B'||h=='C'))||((g=='D'||g=='F')&&(h=='D'||h=='F'))){
				cout<<1;
				if((g=='A'&&h=='B')||(g=='B'&&h=='C')||(g=='D'&&h=='F')){
					cout<<1;
					return 0;
				}else{	
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
	    cout<<"0000";
	    return 0;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
