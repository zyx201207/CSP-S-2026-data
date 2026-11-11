#include<bits/stdc++.h>
using namespace std;
struct twosum{
    int x;
    int os;
};
int main(){
    freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
    int m,n;cin>>m>>n;
    twosum s[200005];
    for(int i=1;i<=n;i++){
        cin>>s[i].x;
        int cnt=0,a=s[i].x;
        while(a!=1){
            a/=2;
            s[i].os++;
        }
    }
    if(m==1){
        int mmax=-1;
        for(int i=1;i<=n;i++){
            if(s[i].x>mmax)mmax=s[i].x;
        }
        cout<<mmax;
        return 0;
    }

}