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

const int LG=30;
int n,m;
vector<int>cus;

signed main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	freopen("and5.in","r",stdin);
//	freopen("and5.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		cus.push_back(a);
	}
	int ans=0;
	for(int i=LG;i>=0;i--){
		int cnt=0;
		for(int j=0;j<cus.size();j++){
			if(cus[j]&(1<<i)){
				cnt++;
			}
		}
		if(cnt<m)continue;
		ans+=(1<<i);
		vector<int>tmp;
		for(int j=0;j<cus.size();j++){
			if(cus[j]&(1<<i)){
				tmp.push_back(cus[j]);
			}
		}
		cus.clear();
		while(tmp.size())cus.push_back(tmp.back()),tmp.pop_back();
	}
	cout<<ans;
	akioi;
}
