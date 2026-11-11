#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    char a[4];
    char b[4];
    char c[4];
    char d[4];
    for(int i=0;i<2;i++){
			cin>>a[i];
	}
	for(int i=0;i<3;i++){
			cin>>b[i];
	}
	for(int i=0;i<2;i++){
			cin>>c[i];
	}
	for(int i=0;i<3;i++){
			cin>>d[i];
	}
	if(a[0]==c[0]&&a[1]==c[1]){
			cout<<1;
		}
	else{
			cout<<0<<0<<0<<0;
			return 0;
		}
    if(b[0]==d[0] && b[1]==d[1]){
        cout<<1;
        if((b[2]>'C'&&d[2]>'C') || (b[2]<='C'&&d[2]<='C')){
            cout<<1;
            if(b[2]>'C'&&d[2]>'C'){
                cout<<1;
            }
            else if(b[2]<='C'&&d[2]<='C'){
                if(b[2]-d[2]==1||d[2]-b[2]==1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
        }
        else{
            cout<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0;
    }
    return 0;
}
