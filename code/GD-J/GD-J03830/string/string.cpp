#include <iostream>
using namespace std;

long long cnt;

struct P{
	int a;
	char c;
}l[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int cur = 1;
	for(int i=1;i<=n;i++) cin>>l[i].a>>l[i].c;
	int left = 1,right = n;
	while(left <= right){
		if(l[left].c != l[right].c){
			if(l[left].a > l[right].a){
				cnt = cnt + l[right].a;
				l[left].a -= l[right].a;
				l[right].a = 0;
				right--;
			}else if(l[left].a < l[right].a){
				cnt = cnt + l[left].a;
				l[right].a -= l[left].a;
				l[left].a = 0;
				left++;
			}else{
				cnt = cnt + l[left].a;
				l[left].a = 0,l[right].a = 0;
				right--;
				left++;
			}
		}else{
			if(l[left].a > l[right].a){
				l[left].a -= l[right].a;
				l[right].a = 0;
				right--;
			}else if(l[left].a < l[right].a){
				l[right].a -= l[left].a;
				l[left].a = 0;
				left++;
			}else{
				l[left].a = 0,l[right].a = 0;
				right--;
				left++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
