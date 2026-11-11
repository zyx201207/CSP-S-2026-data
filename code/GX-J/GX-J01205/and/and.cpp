#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long a,b,c[220000],f[32]={0},mn[222222];
    bool d[220000][33]={false};
    cin>>a>>b;
    for(int z=1;z<=a;z++){
        cin>>c[z];
        long long e=4294967296;
        if(b==1)mn=c[z];
        for(int y=31;y>=0;y--){
            if(c[z]>=e){
                c[z]-=e;
                e/=2;
                d[z][y]=true;
                f[z]++;
            }
        }
    }
    if(b!=1)
    {
        int j=0,h=0,k=0;
        for(int z=31;z>=0;z--){
            if(f[z]>=b){
                h=z-1;
                for(int y=1;y<=a;y++){
                    if(d[y][z]==true){
                        j++;
                        c[j]=y;
                    }
                    else{
                        for(int x=1;x<=31;x++)d[y][x]=0;
                    }
                }
            }
            if(f[z]>=b)break;
        }
        for(int z=h;z>=0;z--){
            for(int y=1;y<=a;y++){
                if(d[y][z]==true){
                    k++;
                }
            }
            if(k>=b){
                for(int y=1;y<=a;y++){
                    if(d[y][z]==false){
                        for(int x=1;x<=31;x++)d[y][x]=0;
                    }
                }
            }
        }
        long long r[211111],j=0;
        bool o[32]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        for(int z=1;z<=a;z++){
            for(int y=0;y<=31;y++){
                if(d[z][y]==true){j++;r[j]++;}
            }
        }
        for(int z=1;z<=j;z++){
            for(int y=0;y<=31;y++){
                if(d[z][y]=false)o[y]=0;
            }
        }
        long long p=1,u=0;
        for(int z=0;z<=31;z++){
            u+=z*p;
            p*=2;
        }
        cout<<p;
    }
    else{
        sort(mn+1,mn+1+a);
        cout<<mn[1];
    }
	return 0;
}
