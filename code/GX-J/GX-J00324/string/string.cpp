#include <bits/stdc++.h>
int cnt;bool op;
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,sum=0;cin>>n;string mx;
    for(int i=0;i<n;i++){
        int num;char s;cin>>num>>s;
        while(num--) {mx+=s;sum+=num;}
    }

    int mid=0;
    if(sum%2==0){
        mid=sum/2+1;op=1;
    }
    else {mid=sum/2;

    }
    if(op){
    for(int i=0;i<mid;i++){
        if(mx[i]!=mx[mx.size()-1-i]) cnt++;
    }
    }
    else {
        for(int i=0;i<mid+2;i++){
            if(mx[mid]!=mx[mid+1]) cnt++;
        }
    }
    cout << cnt;
    return 0;
}

