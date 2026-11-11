#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a=1,b=1,c=1,d=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<a;
    }
    else{
            a=0;
        cout<<0;
    }
    if(a==0){
    	cout<<0;
    	b=0;
	}
    else if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<b;
        }
        else{
                b=0;
            cout<<0;
        }
        if(b==0){
            cout<<0;
            c=0;
        }
        else if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'||s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D'){
           cout<<c;
        }
        else{
            c=0;
            cout<<0;
        }
		if(c==1){
        	if(char(s1[2]+1)==s2[2]||char(s2[2]+1)==s1[2]){
        		cout<<d;
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<0;
		}
    return 0;
}


