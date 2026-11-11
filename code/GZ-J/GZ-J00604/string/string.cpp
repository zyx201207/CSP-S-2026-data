//GZ-J00604 遵义市新蒲中学 杨子曦
#include <bits/stdc++.h>
using namespace std;
struct mi{
	long long l;
	char s;
}a[200005];
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long sum=0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].l >> a[i].s;
	}
	for(int i = 1,j = n;i <= j;){
		if(i == j){
			break;
		}
		if(a[i].s == a[j].s){
			if(a[i].l == a[j].l){
				i++;
				j--;
			}else{
				if(a[i].l > a[j].l){
					a[i].l -= a[j].l;
					j--;
				}else{
					a[j].l -= a[i].l;
					i++;
				}
			}
		}else{
			if(a[i].l > a[j].l){
				sum += a[j].l;
				a[i].l -= a[j].l;
				j--;
			}else{
				sum += a[i].l;
				a[j].l -= a[i].l;
				i++;
			}
		}
	}
	cout << sum;
	return 0;
} 
