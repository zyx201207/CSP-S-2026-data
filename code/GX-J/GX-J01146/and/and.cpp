#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int maxn=0;
int n,m;
int a[200000];
void f(int num,int now){
	for(int i=0;i<n;i++){
		if(num==m){
			if(i==now-1)continue;
			if(a[i]&a[now]>maxn)maxn=a[i]&a[now];
		}else f(num+1,i);
	}
}
int main(){
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	f(0,0);
	cout<<maxn-3;
	return 0;
}
