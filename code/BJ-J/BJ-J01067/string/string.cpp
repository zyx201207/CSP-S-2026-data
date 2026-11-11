#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long n,num[2005] = {},cnt,l,r;
	long long sum = 0;
	char ch[2005] = {};
	cin >> n;
	for(long long i = 1;i <= n;i++){
        cin >> num[i] >> ch[i];
	}
	l = 1;
	r = n;
	cnt = n;
	while(cnt > 0){
        long long minn,a = num[l],b = num[r],c = l,d = r;
        minn = min(a,b);
        if(a > b){
            r--;
            num[l] -= b;
            cnt--;
        }
        else if(a < b){
            l++;
            num[r] -= a;
            cnt--;
        }
        else{
            num[l] = 0;
            num[r] = 0;
            l++,r--;
            cnt -= 2;
        }
        if(ch[c] != ch[d]){
            sum += minn;
        }
	}
	cout << sum;
	return 0;
}
