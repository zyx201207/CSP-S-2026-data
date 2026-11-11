#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node{
    int a;
    char c;
}c[200005];

signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> c[i].a >> c[i].c;
    }
    int cnt = 0;
    for(int i=1, j=n;i<j;){
        if(c[i].c==c[j].c){
            if(c[i].a<c[j].a){
                c[j].a-=c[i].a;
                i++;
            }
            else if(c[i].a>c[j].a){
                c[i].a-=c[j].a;
                j--;
            }
            else{
                i++, j--;
            }
        }
        else{
            if(c[i].a<c[j].a){
                cnt += c[i].a;
                c[j].a-=c[i].a;
                i++;
            }
            else if(c[i].a>c[j].a){
                cnt += c[j].a;
                c[i].a-=c[j].a;
                j--;
            }
            else{
                cnt += c[i].a;
                i++, j--;
            }
        }
    }
    cout << cnt << endl;
    fclose(stdin);
    fclose(stdout);
}