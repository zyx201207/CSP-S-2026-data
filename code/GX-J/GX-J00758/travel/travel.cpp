#include<bits/stdc++.h>
 using namespace std;
 int c1,c2;
 char s1[10],s2[10];
 int a[10],b[10];
 int qwe = 1;
 int main(){
 freopen("travel.in","r",stdin);
 freopen("travel.out","w",stdout);
 cin >> c1;
 for(int i = 1; i <= 3; i++)
    cin >> s1[i];
 cin >> c2;
 for(int i = 1; i <= 3; i++)
    cin >> s2[i];

 if(c1 == c2) cout << 1;
 else{
    cout << "0000";
    return 0;
 }
 a[1] = s1[1] - '0';
 a[2] = s1[2] - '0';
 int a1 = a[1];
 int a2 = a[2];
 b[1] = s2[1] - '0';
 b[2] = s2[2] - '0';
 int b1 = b[1];
 int b2 = b[2];
 if(a1 == b1 && a2 == b2)
    cout << 1;
 else{
    qwe = 0;
    cout << qwe;
 }
 if(qwe == 0){
    cout << "00";
    return 0;
 }
 int ans1 = 0;
 if(s1[3] == 'A') ans1 = 1;
 if(s1[3] == 'B') ans1 = 2;
 if(s1[3] == 'C') ans1 = 3;
 if(s1[3] == 'D') ans1 = 4;
 if(s1[3] == 'F') ans1 = 5;
 int ans2 = 0;
 if(s2[3] == 'A') ans2 = 1;
 if(s2[3] == 'B') ans2 = 2;
 if(s2[3] == 'C') ans2 = 3;
 if(s2[3] == 'D') ans2 = 4;
 if(s2[3] == 'F') ans2 = 5;
 if(ans1 <= 3 && ans2 <= 3) cout << 1;
 if(ans1 >= 4 && ans2 >= 4) cout << 1;
 if(ans1 <= 3 && ans2 >= 4){
    cout << "00";
    return 0;
 }
 if(ans1 >= 4 && ans2 <= 3){
    cout << "00";
    return 0;
 }
 if(ans1 <= 2 && ans2 <= 2)
    cout << 1;
 if(ans1 == 3 && ans2 == 2)
    cout << 1;
 if(ans1 == 2 && ans2 == 3)
    cout << 1;
 if(ans1 == 1 && ans2 == 3)
    cout << 0;
 if(ans1 == 3 && ans2 == 1)
    cout << 0;
 if(ans1 >= 4 && ans2 >= 4)
    cout << 1;
 return 0;
 }
