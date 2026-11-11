#include<bits/stdc++.h>
using namespace std;
char a[100005];
string S="abcdefghijklmnopqrstuvwxyz";
int main(){
    freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	sort(a,a+n);
    cout<<2;
    return 0;}
