#include<bits/stdc++.h>
using namespace std;
int an(int a,int b){
	if(a<b)swap(a,b);
	int f = 1,x=a;
	int ans=0;
	for(int i = 0;i <= log2(x);i++){
		if(a%2==b%2)ans+=f;
		a/=2,b/=2;
		f*=2;
	}
	return ans;
}
int n,m,a[200005],ans,d=1;
int find(int g){
	if(d==m)return a[g];
	d++;
	int aa=0;
	for(int i = 1;i < g;i++)
		aa=max(aa,an(a[g],find(i)));
	d--;
	return aa;
}
int main(){
	freopen("and.in","r".stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	ans=a[1];
	for(int i = 2;i <= n;i++){
		cin>>a[i];
		ans=an(ans,a[i]);
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		cout<<ans;
		return 0;
	}
	cout<<find(n);
	return 0;
}
