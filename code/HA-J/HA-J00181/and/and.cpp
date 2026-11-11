#include <bits/stdc++.h>
using namespace std;
long long a[200005],b,c,n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	c=a[0];
	for(int i=1;i<m;i++){
		while(c&a[i]==0){
			m+=1;
			i++;
		} 
		c=c&a[i];
	}
	if(m>n){
		cout<<0;
		return 0;
	}
	cout<<c;
	return 0;
} 
