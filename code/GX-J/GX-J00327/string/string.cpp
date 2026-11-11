#include <bits/stdc++.h>
using namespace std;

const long long N=1e6;
long long n,ans,z,num;
string s=" ",m;


int main (){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin >>n;
    for (int i=1;i<=n;i++){
    	cin >>z>>m;
    	ans+=z;
        for (int j=1;j<=z;j++) s+='m';
    }
    if (ans%2==0){
    	for (int i=1;i<=ans/2;i++)
    		if (s[i]!=s[ans-i+1])num++;
    }
    else {
    	for (int i=1;i<=ans/2;i++) 
    		if (s[i]!=s[ans-i+1]) num++;
    		if (s[ans/2+1]!=ans/2) num++;
    }
    cout <<num;
	return 0;
}
