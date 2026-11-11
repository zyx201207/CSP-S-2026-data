#include<bits/stdc++.h>
using namespace std;
struct man{
    int num;
    char abc;
};
string wrong;
man m[20004];
long long n,cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cnt = 0;
    cin>>n;//I can't help
    for(int i = 1;i <= n;i++){
        cin>>m[i].num>>m[i].abc;
    }
    int l = n;
    for(int f = 1;f <= n/2;f++){
        if(m[f].abc != m[l].abc){
                if(m[f].num > m[l].num){
                    m[l].abc = m[f].abc;
                    m[l].num = m[f].num;
                    cnt+=m[f].num;
                }
                if(m[f].num < m[l].num){
                    m[f].abc = m[l].abc;
                    m[f].num = m[l].num;
                    cnt+=m[f].num;
                }

        }
        l--;
    }
    cout<<cnt;
    return 0;
}
