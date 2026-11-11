
/*

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
string S;
int L;
int n;
int a[200005];
string c[200004];

int diff(string s1,string s2){
    int sum=0;
    int len=max(s2.size(),s1.size());
    for(int i=0;i<len;i++){
        if(s1[i]!=s2[i]) sum++;
    }
    return sum;
}

signed main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);


    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        L+=a[i];

        for(int j=1;j<=a[i];j++){
            S+=c[i];
        }
    }

    string str1=S.substr(0,L/2);
    //cout<<str1<<endl;
    string str2;
    if(L%2==0){
        str2=S.substr(L/2,L-1);
    }else{
        str2=S.substr(L/2+1,L-1);
    }
    reverse(str2.begin(),str2.end());

    //cout<<str2;
    int ans=diff(str1,str2);
    cout<<ans;
    return 0;

}
