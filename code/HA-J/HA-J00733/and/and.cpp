#include<bits/stdc++.h>//ÎÄ¼þ²Ù×÷ 
using namespace std;
long long a[200020];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
} 
