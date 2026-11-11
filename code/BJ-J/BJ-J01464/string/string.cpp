#include <bits/stdc++.h>
using namespace std;
struct S{
    int a;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long len=0;
    vector<S> s(n);
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        s[i].a=a;
        s[i].c=c;
        len+=a;
    }
    long long cnt=0,l=0,r=n-1;
    while(l<r){
        S a=s[l],b=s[r];
        if(a.c==b.c){
            if(a.a>b.a){
                s[l].a-=b.a;
                r--;
            }else if(a.a<b.a){
                s[r].a-=a.a;
                l++;
            }else{
                l++;
                r--;
            }
        }else{
            if(a.a>b.a){
                cnt+=b.a;
                s[l].a-=b.a;
                r--;
            }else if(a.a<b.a){
                cnt+=a.a;
                s[r].a-=a.a;
                l++;
            }else{
                cnt+=a.a;
                r--;
                l++;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
