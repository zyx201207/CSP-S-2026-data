#include <bits/stdc++.h>
using namespace std;
struct wee{
    int a;
    char c;
}num[200001];
long long len_f[200001];
long long len_b[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int l,r;
    long long cnt = 0,len = 0;
    cin>>n;
    l = 1; r = n;
    for(int f = 1; f<=n; f++){
        cin>>num[f].a>>num[f].c;
        len_f[f] = len_f[f-1]+num[f].a;
        len+=num[f].a;
    }
    for(int f = n; f>=1; f--) len_b[f] = len_b[f+1]+num[f].a;
    while(l<r){
        if(len_f[l]>len/2){
            num[l].a-=(len_f[l]-(len/2+1)+1)*2;
            if(len%2 == 1) num[l].a++;
        }
        if(len_b[r]>len/2){
            num[r].a-=(len_b[r]-(len/2+1)+1)*2;
            if(len%2 == 1) num[r].a++;
        }
        if(num[l].c == num[r].c){
            num[l].a-=min(num[l].a,num[r].a);
            num[r].a-=min(num[l].a,num[r].a);
            if(num[l].a == 0) l++;
            if(num[r].a == 0) r--;
        }
        else {
            cnt+=min(num[l].a,num[r].a);
            num[l].a-=min(num[l].a,num[r].a);
            num[r].a-=min(num[l].a,num[r].a);
            if(num[l].a == 0) l++;
            if(num[r].a == 0) r--;
        }
    }
    cout<<cnt;
    return 0;
}
