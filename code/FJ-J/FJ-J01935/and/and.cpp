#include<bits/stdc++.h>
using namespace std;
int n, m, mx, a[200002];

int ann(int a, int b){
	int sum=0, i=1;
	while(a>0||b>0){
		if (a%2==1 && b%2==1)sum+=i;
		i*=2;
		a=a/2;
		b=b/2;}
	return sum;}

void fm(int j, int mm, int k){
	int mh;
	for (int i=j+1;i<=n-m+k;i++){
		mh=ann(mm, a[i]);
		if (k>=m){
			mx=max(mx, mh);
		}else{
			fm(i, mh, k+1);}}}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		scanf("%d", &a[i]);}
	if (m==1){
		for (int i=1;i<=n;i++){
			mx=max(mx, a[i]);}}
	else if (m==n){
		mx=a[1];
		for (int i=2;i<=n;i++){
			mx=ann(mx, a[i]);}}
	else{
		for (int i=1;i<=n-m+1;i++)fm(i, a[i], 2);}
	cout << mx;
	return 0;
}

