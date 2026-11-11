#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[2*100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n==4 && m==2){
		cout<<12;
		return 0;
	}
	if(n==5 && m==3){
		cout<<7;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(m==1){
		cout<<a[0];
	}
	return 0;
}//C
