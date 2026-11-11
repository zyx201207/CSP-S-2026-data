#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
struct xn{
	long long x;
	char c;
}shu[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	long long len=0;
	while(n--){
		cin >> shu[len].x >> shu[len].c;
		len++;
	}
	long long mid=len/2;
	long long l=(len-1)/2,r=(len+1)/2;
	for(long long i=0;i<mid;i++){
		if(shu[l].c!=shu[r].c){
			int m=min(shu[l].x,shu[r].x);
			cnt+=m;
			shu[l].x-=m;
			shu[r].x-=m;
			if(shu[l].x==0&&shu[r].x==0){
				l--;
				r++;
			}
			else if(shu[l].x==0) l--;
			else r++;
		}
		else{
			l--;
			r++;
		}
	}
	cout << cnt;
	return 0;
}
