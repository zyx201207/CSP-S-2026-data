#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long cnt;
	char c;
};
stu a[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i = 1;i <= n;i++){
		long long m;
		cin>>a[i].cnt>>a[i].c;
	}
	long long ans = 0;
	long long l = 1,r = n;
	while(l < r){
		if(a[l].c == a[r].c){
			if(a[l].cnt > a[r].cnt){
				a[l].cnt -= a[r].cnt;
				a[r].cnt = 0;
				r--;
			}else if(a[l].cnt == a[r].cnt){
				a[l].cnt = 0;
				a[r].cnt = 0;
				l++;
				r--;
			}else{
				a[r].cnt -= a[l].cnt;
				a[l].cnt = 0;
				l++;
			}
		}else{
			ans += min(a[r].cnt,a[l].cnt);
			if(a[l].cnt > a[r].cnt){
				a[l].cnt -= a[r].cnt;
				a[r].cnt = 0;
				r--;
			}else if(a[l].cnt == a[r].cnt){
				a[l].cnt = 0;
				a[r].cnt = 0;
				l++;
				r--;
			}else{
				a[r].cnt -= a[l].cnt;
				a[l].cnt = 0;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
