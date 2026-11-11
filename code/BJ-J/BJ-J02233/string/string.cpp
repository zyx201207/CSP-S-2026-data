#include <bits/stdc++.h>
using namespace std;
int main(){
  freopen("string.in",'r',"cin");
  freopen("string.in",'w',"cout");
  int n,t,cnt=0;
  cin >>n;
  string s="";
  for (int i=0;i<n;i++){
    cin >>j>>t;
    for (int k=0;k<j;k++){
      s+=t;
    }
  }
  for (int i=0;i<n/2;i++){
    if (s[i]!=s[n-1-i]){
      cnt++;
    }
  }
  cout <<cnt;
  return 0;
}