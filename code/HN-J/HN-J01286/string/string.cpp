#include<bits/stdc++.h>
using namespace std;

struct s{
	int x;
	char c;
}a[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long sum=0;
	cin>>n;
	int l=1,r=n;
	for (int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	while (l < r){
		if (a[l].c != a[r].c){
			if (a[l].x > a[r].x){
				sum+=a[r].x;
				a[l].x-=a[r].x;
				r--;
				
			}else if (a[l].x == a[r].x){
				sum+=a[l].x;
				l++;
				r--;
			}else {
				sum+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}
		}else {
			if (a[l].x > a[r].x){
				r--;
				a[l].x-=a[r].x;
			}else if (a[l].x == a[r].x){
				l++;
				r--;
			}else {
				l++;
				a[r].x-=a[l].x;
			}
		}
	}
	cout<<sum;
	return 0;
} 
