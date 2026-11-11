#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
int ans;
int cnt;
struct edge{
	int len;
	char c;
}a[N],b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
		if(a[i].c==a[i-1].c){
			b[cnt].len+=a[i].len;
		}
		else{
			cnt++;
			b[cnt].len+=a[i].len;
			b[cnt].c=a[i].c;
		}
	}
//	cout<<cnt<<'\n';
	//for(int i=1;i<=cnt;i++) cout<<b[i].len<<' '<<b[i].c<<'\n';
	if(cnt==1){
		cout<<0;
		return 0;
	}
	int i=1,j=cnt;
//	cerr<<cnt<<'\n';
	while(i<j){
		int t=min(b[i].len,b[j].len);
		if(b[i].c!=b[j].c) ans+=t;
		b[i].len-=t;
		b[j].len-=t;
		if(b[i].len==0) i++;
		if(b[j].len==0) j--;
 //		cout<<b[i].len<<' '<<b[j].len<<'\n';
	}
	cout<<ans;
	return 0;
}
/*


3
2 a
2 a
2 b

3
2 a
2 b
1 c

5
2 a
2 b
1 h
2 z
3 z
*/
