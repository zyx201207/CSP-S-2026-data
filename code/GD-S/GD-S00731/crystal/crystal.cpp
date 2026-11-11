#\
i\
n\
c\
l\
u\
d\
e\
 \
<\
b\
i\
t\
s\
/\
s\
t\
d\
c\
+\
+\
.\
h\
>
#\
d\
e\
f\
i\
n\
e\
 \
a\
k\
i\
o\
i\
 \
r\
e\
t\
u\
r\
n\
 \
0
#define int long long
using namespace std;

int n,m,a[500001];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal4.in","r",stdin);
//	freopen("crystal4.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1;
	int ml=1,cnt=0,nw=0;
	for(int i=1;i<=n;i++){
		nw+=cnt*(a[i]-a[i-1]);
		cnt++;
		while(nw>m){
			nw-=(a[i]-a[ml]);
			cnt--;
			ml++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	akioi;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
