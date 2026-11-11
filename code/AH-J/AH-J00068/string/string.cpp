#include <bits/stdc++.h>
using namespace std;

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin >> n;
char s[200005];
int f[200005];
for (int i = 0;i<n;i++)
    cin >> f[i] >> s[i];
long long cnt = 0;
int l = 0,r = n-1;//xiabiao
while (l<r){
    int m = min(f[l],f[r]);
    if (s[l] != s[r])
    cnt += m;
    if (f[l] > f[r])
       {

        f[l] -= m;
        r--;}
    else if(f[l] < f[r])
        {l++;
        f[r]-=m;}
    else
    {r--;l++;}

}
cout << cnt;
fclose(stdin);
fclose(stdout);
return 0;
}
