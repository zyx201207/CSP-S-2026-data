#include <bits/stdc++.h>

using namespace std;
int n, a;
char c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n >> a;
    for(int i=0;i<n;i++)
      cin >> c[i];
    if(n==1){
        cout << 0;
    }
    int sum=0;
    for(int i=0;i<n;i++){
      if(c[i]!=c[i+1])
	sum=1;
    }
    if(sum==0)
      cout << 0;
    return 0;
}
