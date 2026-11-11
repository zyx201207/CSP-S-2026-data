# include <bits/stdc++.h>
using namespace std;
char c[10] , c1[10] , s[10] , s1[10];
bool flag , ss , cc;
int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> c >> s >> c1 >> s1;
    if(c[0] == c1[0] && c[1] == c1[1])
       cout << "1";
    else 
       cout << "0" , ss = 1;
       
    if(s[0] == s1[0] && s[1] == s1[1] && !ss)
       cout << "1";
    else 
       cout << "0" , cc = 1;
    
    if(s[2] <= 'C' && s1[2] <= 'C' && !ss && !cc)
     cout << "1";
    else if(s1[2] > 'C' && s[2] > 'C' && !ss && !cc)
     cout << "1";
     else 
      cout << "0" , flag = 1;
   
    if(s1[2] <= 'C' && s[2] >'C')
      cout << "0";
    else if(s1[2] > 'C' && s[2] <= 'C')
      cout << "0";
    else if(abs((int)(s1[2] - s[2])) == 1 && !flag && !ss && !cc)
      cout << "1";
    else cout << "0";
    
	
    
}