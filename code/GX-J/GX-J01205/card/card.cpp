#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    long long a,b,c[11111],h[11111]={0};
    cin>>a>>b;
    for(int z=1;z<=a;z++)cin>>c[z];
    for(int z=1;z<=a;z++){
        long long d[11111]={0},e=0;
        for(int y=z;y<=a;y++){
            for(int x=y;x>=1;x=0){
                if(d[x]==c[y]){
                    for(int j=x;j<=y;j++){
                        d[j]=0;
                        e--;
                    }
                    break;
                }
            }
            e++;
            d[e]=c[z];
        }
        for(int y=1;y<=e;y++){
            h[d[e]]++;
        }
    }
    for(int z=1;z<=e;z++)cout<<h[z]<<" ";
	return 0;
}
