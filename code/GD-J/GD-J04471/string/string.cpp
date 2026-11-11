#include <bits/stdc++.h>
using namespace std;


int n;
long long sum,m;
long long str[100005];

struct S{
	int n;
	char a;
} s [100005];



int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> s[i].n >> s[i].a;
		str[i*2] = sum+1;
		sum += s[i].a;
		str[i*2+1] = sum;
	}
	int l = 0,r = n * 2 - 1;
	for(;s[r / 2 + 1].n > sum/2;r--){
		while(str[l] > sum-str[r]){
			if(s[l/2].a != s[r/2].a){
				m+=s[r/2].n-(s[l/2].n - s[r/2].n);
			}
			r--;
		}
	}
	cout << m;
	return 0;
}
