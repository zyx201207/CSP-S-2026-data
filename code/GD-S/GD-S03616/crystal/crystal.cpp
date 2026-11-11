#include <bits/stdc++.h>
using namespace std;
long long arr[5001000];
double Max=0;

struct qz{
	double froat;
	long long p_i;
}s[5001000];

bool cmp(const qz &a , const qz &b){
	if (a.froat != b.froat) return a.froat > b.froat;
	return a.p_i < b.p_i;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n,m;
	cin >> n >> m;

	for (int i=1;i<=n;i++){
		cin >> arr[i];

	}
	sort (arr+1,arr+n+1);
	for (int i=1;i<=n;i++){
		double f=i/abs(arr[i]);

		s[i].froat = f;
		s[i].p_i=i;
	}
	sort (s+1,s+n+1,cmp);
//	for (int i=1;i<=n;i++){
//		cout << s[i].froat << " " << s[i].p_i << endl;
//	}
	long long m1=1,k=1;
	long long cnt,Max=0;
	while (m1 > 0 && k<=n){
		m1=m;
		cnt=1;
		for (int i=s[k].p_i-1 ; i>=1;i--){
			if (m1 >= abs(arr[s[k].p_i] - arr[i]) ){
				m1-=abs(arr[s[k].p_i] - arr[i]);
				//cout << m1 << endl;
				cnt++;
			}
			else {
				Max=max(cnt,Max);
				break;
			}
		}
		if (m1 > 0){
			
			k++;
		}
	}
	Max=max(Max,cnt);
	cout << Max;
	return 0;
}
