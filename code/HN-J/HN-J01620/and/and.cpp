#include<bits/stdc++.h>
using namespace std;
struct yi{
	long long num,wei=0,sum=0;
}a[99999];
int b;
long long n,m;
bool a1(yi x,yi y){
	return x.num>y.num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].num;
	}
	if(n==1){
		cout<<a[0].num;
		return 0;
	}
	if(n==2){
		if(m==2){
			cout<<max(a[0].num,a[1].num);
		}else{
			cout<<min(a[0].num,a[1].num);
		}
		return 0;
	}
	sort(a,a+n,a1);
	cout<<a[0].num;
	return 0;
}
