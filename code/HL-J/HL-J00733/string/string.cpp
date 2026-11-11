#include<bits/stdc++.h>
using namespace std;

struct node{
	long long num;
	char op;
};

const int maxn = 2e5 + 5;
int n;
long long cnt;
node a[maxn];
//rp++

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i].num);
		cin >> a[i].op;
	}
	int l = 1,r = n;
	while(l <= r){
		if(a[l].op != a[r].op){
			if(a[l].num > a[r].num){
				a[l].num -= a[r].num;
				cnt += a[r].num;
				r--;
			}
			else if(a[l].num < a[r].num){
				a[r].num -= a[l].num;
				cnt += a[l].num;
				l++;
			}
			else{
				cnt += a[r].num;
				r--;
				l++;
			}
		}
		else{
			if(a[l].num > a[r].num){
				a[l].num -= a[r].num;
				r--;
			}
			else if(a[l].num < a[r].num){
				a[r].num -= a[l].num;
				l++;
			}
			else{
				r--;
				l++;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}