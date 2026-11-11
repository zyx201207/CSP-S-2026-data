#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],s; 
bool cmp(long long a,long long b){
	if(a!=b) return a>b;
}
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","s",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	s=a[0];
	for(int i=1;i<m;i++)
		s&=a[i];
		cout<<s;
	return 0;
} 
