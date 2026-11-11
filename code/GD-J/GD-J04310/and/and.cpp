#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005];
vector<long long> vec;
bool cmp(int a,int b){
	return a>b;
}
string str;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int s=a[1];
	for(int i=2;i<=m;i++){
		s=s&a[i];
	}
	cout<<s;
	return 0;
} 
