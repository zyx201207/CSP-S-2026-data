#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,r1,x2,r2;
	bool a=1;
	cin>>x1>>x2>>r1>>r2;
	if(x1!=r1){
        cout<<"0000";
        return 0;
	}
	if(x1==r1){
        if(x2[0]!=r2[0]||x2[1]!=r2[1]){
            cout<<"1000";
        return 0;
        }
	}
	if(x1==r1)cout<<1;
	else cout<<0;
	if(x1==r1){
        if(x2[0]==r2[0]&&x2[1]==r2[1])cout<<1;
        else cout<<0;
	}
	if(x1==r1){
        if(x2[0]==r2[0]&&x2[1]==r2[1]){
            if(x2[2]<='C'&&r2[2]<='C'||x2[2]>='D'&&r2[2]>='D')cout<<1;
            else{
                cout<<0;
                a=0;
            }
        }
	}
	if(x2[2]+1==r2[2]||x2[2]-1==r2[2]){
            if(a)cout<<1;
        else cout<<0;
    }
}
