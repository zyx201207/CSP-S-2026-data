#include <bits/stdc++.h>
using namespace std;
long long n;
struct loc{
	long long l;
	char s;
}a[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >> a[i].l >>a[i].s;
	}
	long long left=1,right=n,sum=0;
	while(left<right){
		if(a[left].s==a[right].s){
			if(a[left].l<a[right].l){
				a[right].l-=a[left].l;
				left++;
			}else if(a[left].l==a[right].l){
				left++;
				right--;
			}else{
				a[left].l-=a[right].l;
				right--;
			}
		}else{
			if(a[left].l<a[right].l){
				sum+=a[left].l;
				a[right].l-=a[left].l;
				left++;
			}else if(a[left].l==a[right].l){
				sum+=a[left].l;
				left++;
				right--;
			}else{
				sum+=a[right].l;
				a[left].l-=a[right].l;
				right--;
			}
		}
	}
	cout << sum;
	return 0;
}
