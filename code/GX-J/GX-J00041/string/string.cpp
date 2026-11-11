#include <bits/stdc++.h>
using namespace std;
string st;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    int last=1,num=1;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        string y;cin>>y;
        num+=x;
        for (int i=last;i<=num;i++) st+=y;
        last=num+1;
    }
    if (st[0]==st[num-1]) {cout<<0;return 0;}
    int mid=(num-1)/2+1;
    if(num/2!=0){
        if (st[mid] != st[mid+1] && st[mid] != st[mid-1]) cout<<(num-1)/2;
        else if(st[mid] != st[mid+1] && st[mid] == st[mid-1]) cout<<(num-1)/2;
        else if(st[mid] == st[mid+1] && st[mid] == st[mid-1]){
            int z=int (st[mid]);
            z=z+1-97;
            int l=0;
            for (int i=mid;i<=num;i++) {
                l++;
                if (st[i]==st[z]) {break;}

            }
            cout<<(num-1)/2-l;
        }
    }
    else{
        mid=num/2;
        if (st[mid]==st[mid-1] && st[mid]!=st[mid+1]) cout<<num/2;
        else if( st[mid]==st[mid+1] && st[mid]!=st[mid-1]){
            int z=int (st[mid]);
            z=z+1-97;
            int l=0;
            for (int i=mid;i>=0;i--) {
                l++;
                if (st[i]==st[z]) {break;}

            }
            cout<<num/2-l;
        }

    }
    return 0;
}
