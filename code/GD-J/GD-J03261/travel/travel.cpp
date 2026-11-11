#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int a,b;
    char c,d;
    a=(s1[0]-'0')*10+s1[1];
    b=(s2[0]-'0')*10+s2[1];
    c=s1[2];
    d=s2[2];
    if (c>d) swap(c,d);
    cout<<(c1==c2);
    cout<<((c1==c2)&&(a==b));
    cout<<(((c1==c2)&&(a==b))&&((c=='A'&&d=='B')||(c=='A'&&d=='C')||(c=='B'&&d=='C')||(c=='D'&&d=='F')));
    cout<<(((c1==c2)&&(a==b))&&((c=='A'&&d=='B')||(c=='B'&&d=='C')||(c=='D'&&d=='F')));
    return 0;
}
