#include <bits/stdc++.h>
using namespace std;
long long n,le,num;
string aaa;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(long long i=0;i<n;i++){
    	long long a;
    	string b;
    	cin>>a>>b;
    	le+=a;
    	for(int i=0;i<a;i++){
    		aaa=aaa+b;
		}
	}
	for(long long i=0;i<le/2;i++){
		if(aaa[i]!=aaa[le-1-i]){
			num++;
		}
	}
	cout<<num;
    return 0;
}
