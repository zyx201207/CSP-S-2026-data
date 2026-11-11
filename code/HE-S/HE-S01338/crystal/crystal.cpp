#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5*5+5;
int n;
long long m;
long long a[maxn],q[maxn];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld" ,&n ,&m);
	for (int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
//	for (int i = 1;i <= n;i++){
//		cout << a[i];
//	}
//	cout << endl;
	int tot=2;
	for (int i = 2;i <= n;i++){
		q[tot] = a[i]-a[i-1];
		q[tot] = q[tot-1] + q[tot];
		tot++;
	}

//	for (int i = 2;i <= n;i++){
//		cout << q[i] << endl;
//	}
//	cout << endl;
	int ss=0,start=0,end=1;
	bool bl = true;
	for (int i = 2;i <= n;i++){
		m-=(i-1)*(q[i]-q[i-1]);
		//q[i]=0;
		
		
		if (ss == 0){
			if (a[i-1] != a[i]) start = end,end = i;
		}
		if (m < 0 && (m+(0-m))-(i)*(q[i+1]-q[i]) == 0 && bl){
			//cout << m << endl;
			ss=m+(i-1)*(q[i]-q[i-1]);
			//cout << ss << endl;
			m=0;
			bl=false;
		}
//		cout << m << endl;
//		cout << start << ' ' << end << endl;
		if (m < 0 || i == n){
			if (ss != 0){
				int ans=i;
				//cout << ans << endl;
				for (int j = start;j < end;j++){
					if (ss >= 0 && ss-(a[end]-a[start]) >= 0){
						ss-=(a[end]-a[start]);
						ans--;
						//cout << 111 << endl;
					}
					else break;
				}
				cout << ans;
				return 0;
			}
			if (m < 0) printf("%d", i-1);
			else printf("%d", i);
			break;
		}
		
	}
	//cout << 1;
	return 0;
}
