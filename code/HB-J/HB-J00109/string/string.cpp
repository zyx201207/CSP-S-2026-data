#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int str[200005][2];
char c;
int a,n,size;
long long ans;
int r;
int l = 0;
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 0; i< n;i++)
    {
		cin >> a >> c;
		str[i][0] = a;
		str[i][1] = (int)c;
	}
    //cout << str;
    r = n;
    while(l < r)
    {
		if( str[l][0] == 0)
		{
			l++;
		}
		if(l == r)
		{
			break;
		}
		if( str[r][0] == 0)
		{
			r--;
		}
		if(l == r)
		{
			break;
		}
		int gg = min(str[l][0],str[r][0]);
		str[l][0]-=gg;
		str[r][0]-=gg;
		if( str[l][1] != str[r][1])
		{
			ans+=(long long)gg;
		}
	}
	cout <<ans;
    return 0;
}
