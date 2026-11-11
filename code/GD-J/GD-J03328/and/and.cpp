#include<bits/stdc++.h>
using namespace std;
int f(int x){
	int ans=0;
	while(x){
		ans+=x%2;
		x/=2;
	}
	return ans;
} 
int n,maxn,m;
struct stu{
	int nu;
	int br;
}a[100005];

bool cmp(stu aa,stu bb){
	if(aa.br!=bb.br) return aa.br>bb.br;
	else return aa.nu>bb.nu;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		int t;
		cin>>t;
		a[i].nu=t;
		a[i].br=f(t);
	}
	sort(a,a+n,cmp);
	maxn=a[0].nu;
	for(int i=1;i<m;i++){
		maxn=maxn&a[i].nu;
	}
	cout<<maxn;
	return 0;
} 
