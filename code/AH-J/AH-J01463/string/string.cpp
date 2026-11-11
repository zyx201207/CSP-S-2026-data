#include<bits/stdc++.h>
using namespace std;
long long longs=0;
/*struct node{
	long long l,r;
	char k;
}m[200005];
* */
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string v="";
	int t;
	unsigned long long cnt=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long n,z;
		char c;
		cin>>n>>c; z=n;
		/*m[i].k=c;
		m[i].l=longs+1;
		longs+=n;
		m[i].r=longs;
		}for(int i=1;i<=t;i++){
		
		}*/
		while(z--){
			v+=c;
		}
	}for(int i=0;i<(v.size()/2);i++){
		if(v[i]!=v[v.size()-i-1]){
			cnt++;
		}
	}cout<<cnt;
	return 0;
}
