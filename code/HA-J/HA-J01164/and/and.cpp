#include<bits/stdc++.h>
using namespace std;
int l[200005];
int max;
int a[200005];
bool cmp(int n){
	int i;
	while(a[i]!=0){
		if(n==a[i]) return false;
	}
	return true;
}
int d=1;
int f(int n,int m,int max){
	int ans;
	ans = max&l[1];
	for(int i=1;i<=n;i++){
		if(l[i]&max>ans and cmp(i)) {
			ans=max&l[i];
			d++;
			a[d]=i;
		}
	}
	m--;
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	int max;
	max=l[1]&l[2];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(l[j]&l[i]>max and i!=j){
				max=l[j]&l[i];
				a[d]=i;
				d++;
				a[d]=j;
			}
		}
	}
	x-=2;
	cout<<f(n,x,max);
	return 0;
}
