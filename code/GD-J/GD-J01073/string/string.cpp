#include <bits/stdc++.h>
using namespace std;
long long n,ans;
string s = " ",a,b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++){
		long long x;
		char c;
		cin >> x >> c;
		for(long long j = 1;j <= x;j++){
			s = s + c;
		}
	}
	long long len = s.size() - 1;
	if(len % 2 == 0){
		len /= 2;
		for(long long i = 1;i <= len;i++){
			a[i] = s[i];
		}
		for(long long i = len + 1;i <= len * 2;i++){
			b[i - len] = s[i];
		}
		for(long long i = 1;i <= len;i++){
			if(a[i] != b[len - i + 1]){
				ans++;
			}
		}
	}else{
		len = (len - 1) / 2;
		for(long long i = 1;i <= len;i++){
			a[i] = s[i];
		}
		for(long long i = len + 1;i <= len * 2;i++){
			b[i - len] = s[i];
		}
		for(long long i = 1;i <= len;i++){
			if(a[i] != b[len - i + 1]){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
} 

/*
#include <bits/stdc++.h>
using namespace std;
long long n,len;
struct s {
	long long x;
	char y;
}a[200001],b[200001],c[200001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> a[i].x >> a[i].y;
		len += a[i].x;
	}
	long long k = 0,l = 0;
	if(len % 2 == 0){
		len /= 2;
		long long cnt = 0;
		for(long long i = 1;i <= len;i++){
			k++;
			if(cnt + a[i].x < len){
				b[k].x = a[i].x,b[k].y = a[i].y;
				cnt += a[i].x;
			}else if(cnt + a[i].x == len){
				b[k].x = a[i].x,b[k].y = a[i].y;
				break;
			}else{
				b[k].x = len - cnt,b[k].y = a[i].y;
				break;
			}
		}
	}else{
		len = (len - 1) / 2;
		long long cnt = 0,u;
		bool f = false;
		for(long long i = 1;i <= n;i++){
			k++;
			if(cnt + a[i].x < len){
				b[k].x = a[i].x,b[k].y = a[i].y;
				cnt += a[i].x;
			}else if(cnt + a[i].x == len){
				b[k].x = a[i].x,b[k].y = a[i].y;
				break;
			}else{
				b[k].x = len - cnt,b[k].y = a[i].y;
				u = i;
				f = true;
				break;
			}
		}
	}
	return 0;
}
*/
