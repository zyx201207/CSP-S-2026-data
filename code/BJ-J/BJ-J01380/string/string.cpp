#include <iostream>
using namespace std;

struct node{
	long long l,r;
	char val;
};

int n;
node str[200005];
long long a,cnt;
char c;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	str[0].r = 0;
	for(int i = 1;i <= n;i++){
		cin >> a >> c;
		str[i].l = str[i-1].r + 1;
		str[i].r = str[i].l + a - 1;
		str[i].val = c;
	}
	int l = 1,r = n;
	long long lpos = 1,rpos = str[n].r;
	for(;l <= r && lpos <= rpos;){
		long long r1 = str[l].r,l2 = str[r].l;
		char v1 = str[l].val,v2 = str[r].val;
		if(v1 == v2){
			long long dis = min(r1 - lpos + 1,rpos - l2 + 1);
			lpos += dis;
			rpos -= dis;
			if(lpos > r1) l++;
			if(rpos < l2) r--;
		}else{
			long long dis = min(r1 - lpos + 1,rpos - l2 + 1);
			lpos += dis;
			rpos -= dis;
			if(lpos > r1) l++;
			if(rpos < l2) r--;
			cnt += dis;
		}
	}
	cout << cnt;
	return 0;
}
