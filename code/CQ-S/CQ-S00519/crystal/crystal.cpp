#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,m;
long long a[N];
long long cnt_front[N],cnt_back[N],cnt_back2[N]; //ǰ׺�͡���׺��
int ans=1;
long long add=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	// cout << '!';
	sort(a+1,a+1+n);

	// cout << 1 << '\n';

	for (int i=2;i<=n;i++){
		cnt_front[i]=a[i]-a[i-1];
		cnt_front[i]+=cnt_front[i-1];
		cnt_back[n-i+1]=a[n-i+2]-a[n-i+1];
		cnt_back[n-i+1]+=cnt_back[n-i+2];
		cnt_back2[n-i+1]=cnt_back[n-i+1]+cnt_back2[n-i+2];
	}
	for (int i=n;i>1;i--){
		a[i]=a[i]-a[i-1];
	}
	a[1]=0;

	// cout << 2 << '\n';

/*
	for (int i=1;i<=n;i++){
		cout << a[i] << ' ';
	}
	cout << '\n';
	for (int i=1;i<=n;i++){
		cout << cnt_front[i] << ' ';
	}
	cout << '\n';
	for (int i=1;i<=n;i++){
		cout << cnt_back[i] << ' ';
	}
*/

	for (int i=2;i<=n;i++){
		add+=(i-1)*a[i];
		if (add<=m){
			ans=i;
			continue;
		}

		int mid,midd,l=0,r=i-1;
		long long k;
		while (l<r){
			mid=(l+r)>>1;
			k=cnt_back2[i-mid]-cnt_back[i]*(i-(i-mid-1));
			if (k<=m){
				l=mid+1;
			}
			else {
				r=mid;
			}
		}
		ans=max((l+1),ans);
		/*
		while (l<r){
			mid=(l+r+1)>>1;
			if (k>m) {
				k-=(cnt_front[i]*(mid-l)-cnt_front[mid-1]+cnt_front[l-1]);
				l=mid;
			}
			else {
				midd=(2+mid)>>2;
				k+=(cnt_back[midd]-cnt_back[i]);
				l=midd;
			}
		}
		ans=max((i-l+1),ans);
		cout << ans << ' ';
		*/
	}
	cout << ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/

