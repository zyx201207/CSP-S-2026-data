//GZ-J00460 贵阳市第十七中学 徐廷蔚
#include<bits/stdc++.h>
using namespace std;
int n = 0;
struct node{
	long long a;
	char c;
}arr[200005];
long long tot = 0;
long long half = 0;
long long cost = 0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;	
//	scanf("%d",&n);
	for(int i = 1;i <= n;i ++) {
		cin >> arr[i].a >> arr[i].c;
	//	scanf("%lld",&arr[i].a);
	//	char xishou;
//		scanf("%c",&xishou);
//		scanf("%c",&arr[i].c);
		//scanf("%c",&xishou);
		tot += arr[i].a;
	}
	half = (tot + 1) >> 1;
	int l_id = 1,r_id = n;
	long long l_sub = 0,r_sub = 0;
	long long l_sum = 0,r_sum = 0;
	while(l_id < r_id) {
		//suit rule
		if(arr[l_id].c == arr[r_id].c) {
			long long movel = arr[l_id].a - l_sub;
			long long mover = arr[r_id].a - r_sub;
			if(movel < mover) {
				l_id ++;
				l_sub = 0;
				r_sub += movel;
				// TODO for l_sum?
			} else if(movel == mover) {
				l_id ++;
				r_id --;
				l_sub = 0;
				r_sub = 0;
			} else {
				r_id --;
				r_sub = 0;
				l_sub += mover;
			}
		} else { // no suit rule
			long long movel = arr[l_id].a - l_sub;
			long long mover = arr[r_id].a - r_sub;
			if(movel < mover) {
				l_id ++;
				l_sub = 0;
				r_sub += movel;
				cost += movel;
				// TODO for l_sum?
			} else if(movel == mover) {
				l_id ++;
				r_id --;
				l_sub = 0;
				r_sub = 0;
				cost += mover;
			} else {
				r_id --;
				r_sub = 0;
				l_sub += mover;
				cost += mover;
			}			
		}
	}	
	cout << cost;
	return 0;
}
