#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int c,t;
vector<int>g[505];
struct oo{
	int c,t;
}r[505];
struct ooo{
	int t;
}p[505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		cout<<n-k<<endl;
	}
	return 0;
}
/*
     A             CCCCC      
    AA            C     C
   A  A          C       
  AAAAAA         C
 A      A         C     C
A        A         CCCCC
*/
