#include<bits/stdc++.h>
using namespace std;


int n;
long long m;
long long a[3000000];
string c;
string s;
long long num,ans;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
//ios::sync_with_stdio(false);
//cin.tie(0);
	cin>>n;
	for(int i = 0;i<=n-1;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
		for(long long j = 0;j<=a[i]-1;j++){
			s[m]=c[i];
			m++;

		}
	}
	for(long long i = 0;i<=num-1;i++){
		if((s[i]!=s[num-1])&&i<=num){
				ans++;
			}
		num--;
		if(num<i)break;
	}
	cout<<ans;


return 0;
}

