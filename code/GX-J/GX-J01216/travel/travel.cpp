#include<bits/stdc++.h>
using namespace std;

int c1,c2,a,b;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    a=(s1[0]-'0')*10+(s1[1]-'0');
    b=(s2[0]-'0')*10+(s2[1]-'0');
    if(c1!=c2)
      cout << 0000;
    else  
      if(a!=b)
        cout << 1000;
      else  
        if((s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') || (s1[2]>='D' && s1[2]<='E' && s2[2]>='D' && s2[2]<='E'))
          if(s1[2]+1==s2[2] || s2[2]+1==s1[2])
            cout << 1111;
          else
            cout << 1110;
        else
          cout << 1100;
    return 0;	
}
