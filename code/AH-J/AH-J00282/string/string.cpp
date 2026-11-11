#include <bits/stdc++.h>
using namespace std;
long long n,a,b,sum;
string c,s;
int main(){
    frepoen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		for(long long i=1;i<=a;i++){
			s+=c;
		}
	}
	b=s.size()/2;
	for(long long i=0;i<b;i++){
		if(s[i] != s[s.size()-i-1]){
			sum++;
		}
 }
	cout<<sum;	
	return 0;
}
