#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }else{
        cout<<0;
    }
    if(a==c && b[1]==d[1] && b[0]==d[0]){
        cout<<1;
    }else{
        cout<<0;
    }
    if(a==c && b[1]==d[1] && b[0]==d[0]){
        if(b[2]=='A' || b[2]=='B' || b[2]=='C'){
            if(d[2]=='A' || d[2]=='B' || d[2]=='C'){
                cout<<1;
            }else{
                cout<<0;
            }
        }else{
            if(d[2]=='D' || d[2]=='E'){
                cout<<1;
            }else{
                cout<<0;
            }
        }
    }else{
        cout<<0;
    }
    if(a==c && b[1]==d[1] && b[0]==d[0]){
		if(abs(b[2]-d[2])==1){
			if(b[2]=='C' && d[2]=='D'){
				cout<<0;
			}else if(b[2]=='D' && d[2]=='C'){
				cout<<0;
			}else{
				cout<<1;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
    return 0;
}
