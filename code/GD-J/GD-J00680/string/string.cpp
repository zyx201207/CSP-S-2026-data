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

int n,a[200001];
char c[200001];

signed main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	freopen("string6.in","r",stdin);
//	freopen("string6.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n,ans=0;
	while(1){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}else if(a[l]==a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++,r--;
		}else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		if(l>=r)break;
	}
	cout<<ans;
	akioi;
}
