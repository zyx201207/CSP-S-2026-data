#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,r,x;
int main(){
  	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	r=(c1[0]-'0')*10+c1[1]-'0';
	x=(c2[0]-'0')*10+c2[1]-'0';
	if(r==x){
        cout<<1;
        int n=(s1[0]-'0')*10+s1[1]-'0';
        int m=(s2[0]-'0')*10+s2[1]-'0';
        if(n==m){
            cout<<1;
            char a=s1[2];
            char b=s2[2];
            int u=a-'A';
            int v=b-'A';
            if(u<=2&&v<=2){
                cout<<1;
                int f=u-v;
                if(abs(f)==1){
                    cout<<1;
                    return 0;
                }else{
					cout<<0;
					return 0;
				}
            }else if(u==3&&v==5){
                cout<<1<<1;
            }else if(u==5&&v==3){
                cout<<1<<1;
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
            return 0;
        }
	}else{
        cout<<0<<0<<0<<0;
        return 0;
	}
    return 0;
}

