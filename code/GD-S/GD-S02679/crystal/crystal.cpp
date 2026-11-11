#include<bits/stdc++.h>
using namespace std;
int u(int n, int x, int a[]){
	int mid = (n+1)/2, l=0, r=n;
	while(1){
		if(r==l||(!(a[l]==x)&&r-l==1))return r;
		if(a[mid] > x){
			r=mid;
			
		}else if(a[mid] < x){
			l=mid;
		}else{
			return mid;
		}
		mid=(l+r+1)/2;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, m, cnt=0, maxn=-1;
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int m1=a[0], m2=a[n-1];
	for(int i = m1+1; i <= m2; i++){
		int b = 0;cnt=0;
		int c= u(n, i, a);
		for(int j = c; j >= 0; j--){
			if(a[j] < i) b+=(i-a[j]);
			if(b>m)break;
			cnt++;
		}
		maxn=max(cnt, maxn);
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
} 
