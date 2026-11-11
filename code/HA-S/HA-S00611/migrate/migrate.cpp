#include<bits/stdc++.h>
#include<queue>
using namespace std;
/*
XIE LAO SHI ZUI SHUAI  XIE LAO SHI ZUI SHUAI 
XIE LAO SHI ZUI SHUAI  XIE LAO SHI ZUI SHUAI 
XIE LAO SHI ZUI SHUAI  XIE LAO SHI ZUI SHUAI 
PIAN FEN PIAN FEN PIAN FEN PIAN FEN PIAN FEN 
PIAN FEN PIAN FEN PIAN FEN PIAN FEN PIAN FEN 
PIAN FEN PIAN FEN PIAN FEN PIAN FEN PIAN FEN 
*/
const int N=2e6+5;
long long a[N];
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n;
		long long d;
		cin>>n>>d;
		
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		cout<<(a[n]-a[1])/(d)<<" \n";
	}
	return 0;
}