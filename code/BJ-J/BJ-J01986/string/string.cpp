#include<bits/stdc++.h>
using namespace std;
int a,x=0,ans=0;
string y;
int main{
    ios::sync_with_stdio(flase);
    cin.tie();
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a;
    if(a==1){string y;
        cout << 0;
    }else if(a==2){
        int b1,b2;
        string c1 , c2;
        cin >> b1 >> c1;
        cin >> b2 >> c2;
        if(b1 > b2){
            int l=b2;
        }else{
            int l=b1;
        }
        if(c1 == c2){
            cout << 0;
        }else{
            cout << l;
        }
    }else{
        for(int i = 1;i<=a;i++){
            int b, c;
            cin >> b >> c;
            for(int j=1;j<=b;j++){
				y+=c;
            }
            if(b==1){
                x++;
            }
        }
        if(x == a){
            for(int z=0;z<x/2;z++){
            	if(y[z] != y[x-z]){
            		ans+=1;
            	}
            }
        }else{
        	for(int z=0;z<x/2;z++){
            	if(y[z] != y[x-z]){
            		ans+=1;
            	}
            }
        }
        cout << ans;
    }
    return 0;
}