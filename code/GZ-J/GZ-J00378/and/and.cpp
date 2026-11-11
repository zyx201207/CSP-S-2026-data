//GZ-J00378,贵阳市中天中学，郑景元 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20010],x=0;
int cmp(int a,int b){
	return a<b;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1,cmp);
	cout<<a[m];
	return 0;
}
