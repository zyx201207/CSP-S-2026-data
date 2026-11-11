#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],t=0,ans=0;
char c[N];
string d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			d+=c[i];
		}
	}
	long long q=d.size();
	for(long long i=0;i<=q/2;i++){
		if(d[i]!=d[q-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
//Trick||Treat!
/*


3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


*/
