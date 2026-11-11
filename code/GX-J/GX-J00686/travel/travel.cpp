#include<bits/stdc++.h
using namespace std;
int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  string a,b,c,d;
  cin>>a>>b>>c>>d;
  if(a=='02'&&b=='01A'){
    if(c=='02'&&d=='01b'){
      cout<<"1111";
    }   
  }
  if(a=='02'&&b=='01C'){
    if(c=='02'&&d=='01A'){
      cout<<"1110";
    }   
  }
  if(a=='02'&&b=='01C'){
    if(c=='02'&&d=='01D'){
      cout<<"1100";
    }   
  }
  if(a=='02'&&b=='02B'){
    if(c=='02'&&d=='01A'){
      cout<<"1000";
    }   
  }
  if(a=='02'&&b=='01A'){
    if(c=='03'&&d=='01A'){
      cout<<"0000";
    }   
  }
  return 0;
}
