#include<bits/stdc++.h>
using namespace std;

#define LEN (int)(2*(1e5))+5
unsigned long long n,cs[LEN],ti;
unsigned long long cnt;
char ss[LEN],tc;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	int tmpn = n;
	int idx=0;
	for (int i=0;i<tmpn;i++) {
		cin >> ti >> tc;
		if (idx > 0 && tc == ss[idx-1]) {
			cs[idx-1] += ti;
			n--;
		} else {
			cs[idx] = ti;
			ss[idx] = tc;
			idx++;
		}
	}
//	2 a
//	2 b
//	1 c
//	

	for (int i=0;i<n/2;i++) {
		if ((ss[i] == ss[n-i-1]))  {
			cnt += max(cs[i],cs[n-i-1]) - min(cs[i],cs[n-i-1]); 
//			cout << cnt << ":" << endl;
		} else if (ss[i] != ss[n-i-1] ){
			cnt += max(cs[i],cs[n-i-1]);
//			cout << cnt << "'" << endl;
		}
	}
	
	cout << cnt << "\n";
	return 0;
	
} 
