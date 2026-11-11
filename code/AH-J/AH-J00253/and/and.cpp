#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=1e6+5;
const int mod=1e9+7;
const int inf=2e9;

int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while('0'<=ch && ch<='9'){x=x*10+(int)(ch-'0');ch=getchar();}
	return x*f;
}

int n,m;
int b[N];
int a[N][32];
bool v[N];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> b[i];
		v[i]=1;
		int bf=b[i],p=0;
		while(bf){
			a[i][p++]=bf%2;
			bf/=2;
		}
	}
	for(int j=30;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=a[i][j];
		}
		if(cnt>=m){
			int sum=0;
			for(int i=1;i<=n;i++) if(v[i]){
				sum+=a[i][j];
			}
			if(sum<m) break;
			for(int i=1;i<=n;i++) if(v[i]){
				v[i]=a[i][j];
			}
			if(sum==m) break;
		}
	}
	int ans=-114514,cnt=0;
	for(int i=1;i<=n;i++) if(v[i] && cnt<=m){
		if(ans==-114514) ans=b[i];
		else ans=ans&b[i];
		cnt++;
	}
	cout << ans;
	return 0;
}

//居然写出来了，痛哭 
//300pts应该有了吧 

