#include <bits/stdc++.h>
using namespace std;
long long n,ai,a[200005],cnt=0,h=0,si=0,x;
char b;
string s[200005],temp;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ai>>temp;
        a[i]=ai;
        s[i]=temp;
        si+=ai;
    }
    int i=0,ii=n-1;
    while(i!=ii){
        if(s[i] == s[ii]){
            if(a[i]<=a[ii]){
                a[ii]-=a[i];
                a[i]-=a[i];
                if(a[i]==0){
                    i++;
                }
                if(a[ii]==0){
                    ii--;
                }
                continue;
            }
            else{
                a[i]-=a[ii];
                a[ii]-=a[ii];
                if(a[ii]==0){
                    ii--;
                }
                continue;
            }
        }
        else if(s[i]!=s[ii]){
            if(a[i]<=a[ii]){
                h+=a[i];
                a[ii] -= a[i];
                a[i] -= a[i];
                if(a[i]==0){
                    i++;
                }
                if(a[ii]==0){
                    ii--;
                }
                continue;
            }
            else{
                h+=a[ii];
                a[i]-=a[ii];
                a[ii]=0;
                if(a[ii]==0){
                    ii--;
                }
                continue;
            }
        }
    }

    cout<<h;
    return 0;
}
