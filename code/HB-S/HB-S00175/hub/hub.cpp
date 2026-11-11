#include<bits/stdc++.h>
#define ll long long
#define db double
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int n;

int rd() {
    int num=0,k=1,c=getchar();
    while(!isdigit(c)) {
        if(c=='-') k=-1;
        c=getchar();
    }
    while(isdigit(c)) {
        num=num*10+c-48;
        c=getchar();
    }
    return num*k;
}
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    
    return 0;
}
