#include<bits/stdc++.h>
using namespace std;
struct sebit{
	int a;
	int s;
};
bool cmp(sebit a,sebit b){
	if(a.s>=b.s) return 1;
	else return 0;
} 
bool anwz(int n,int i){
	return ((n>>i)&1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	sebit a[222222];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		a[i].s=0;
		int lix=0;
		while((1<<lix)<=a[i].a) lix++; 
		for(int j=0;j<=lix;j++){
			a[i].s+=anwz(a[i].a,j);
		}
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1].a;
	for(int i=2;i<=m;i++){
		ans=(ans&a[i].a);
	}
	cout<<ans;
	return 0;
}

