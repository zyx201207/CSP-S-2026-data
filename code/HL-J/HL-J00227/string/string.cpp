#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long int  n,a,sum=0;
    cin>>n;
    char c;
    deque <int> q;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        cin>>c;
            for(int i=1;i<=a;i++){
                    q.push_front(c);
            }
    }
    for(int i=1;i<=q.size()-1;i++)
    {
        for(int j=q.size()-1;j>=1;j--){
            if(j<=i)
            {
                cout<<sum;
                return 0;
            }
            if(q[i]!=q[j])
            {
                sum++;
            }
        }
    }
}
