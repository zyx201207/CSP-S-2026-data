#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
char aa[N];int cc[N];
char a[N];int c[N];
long long summ,sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> cc[i] >> aa[i];
		sum += cc[i];
	}
//	int t;//
	summ = sum;
	summ /= 2;
	bool f = 0;
	for(long long i = 1;i <= n;i++){
		if(!f){
			if(cc[i]  <= summ){
				a[i] = aa[i];c[i] = cc[i];
				summ -= cc[i];
			}else{
				a[i] = aa[i];   c[i] = summ;
				a[i+1] = aa[i]; c[i+1] = cc[i]-summ;
				if(sum % 2 == 1){
					c[i+1]--;
				}
//				t = i;//
				f = 1;
			}
		}else{
			a[i+1] = aa[i];
			c[i+1] = cc[i];
		}
	}
	n++;
	/*
	cout << "*\n";
	for(long long i = 1;i <= n;i++){
		cout << c[i] << " " << a[i] << endl;
	}
	cout << "*\n";
	*/
	sum /= 2;
	long long j = n;
	for(long long i = 1;i <= sum;){
		if(a[i] == a[j]){
			if(c[i] > c[j]){
				c[i]-=c[j];
				c[j] = 0;
				j--;
			}else if(c[i] == c[j]){
				c[i] = c[j] = 0;
				j--;i++;
			}else{
				c[j]-=c[i];
				c[i] = 0;
				i++;
			}
		}else{
			if(c[i] > c[j]){
				ans +=c[j];
				c[i]-=c[j];
				c[j] = 0;
				j--;
			}else if(c[i] < c[j]){
				ans += c[i];
				c[j]-=c[i];
				c[i] = 0;
				i++;
			}else{
				ans += c[i];
				c[i] = c[j] = 0;
				i++;j--;
			}
		}
//		cout << "*\n";
//		for(long long h = 1;h <= n;h++){
//			cout << c[h] << "& " << a[h];
//			if(h == i || h == j) cout << "-";
//			cout << endl;
//		}
//		cout << "*\n";
//		if(hh > 21) break;
	}
	cout << ans;
	return 0;
}
