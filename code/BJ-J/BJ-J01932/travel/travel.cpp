#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;



int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    cout<<(c1==c2)<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])<<
    (c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'))<<
    (c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(s1[2]>='D'&&s2[2]>='D'||s1[2]<='C'&&s2[2]<='C'&&abs(s1[2]-s2[2])<=1))<<endl;

    return 0;
}

