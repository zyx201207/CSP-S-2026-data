#include <bits/stdc++.h>
#define int long long
using namespace std;
int v[200010];
char ch[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string src="";
    for (int i=1;i<=n;i++)
        cin>>v[i]>>ch[i];
    int head=1,tail=n;
    int answer=0;
    while (head<tail){
        if (v[head]<v[tail]){
            v[tail]-=v[head];
            if (ch[head]!=ch[tail])
                answer+=v[head];
            head++;
        }else if (v[head]>v[tail]){
            v[head]-=v[tail];
            if (ch[tail]!=ch[head])
                answer+=v[tail];
            tail--;
        }else {
            if (ch[head]!=ch[tail])
                answer+=v[tail];
            head++,tail--;
        }
    }
    cout<<answer<<endl;
    return false;
}
