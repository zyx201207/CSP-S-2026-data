#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long q,w;
	cin>>q>>w;
	long long a[q+1];
	long long s=0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	sort(a+1,a+q+1);
	s=a[q];
	for(int i=q-1;i>q-w;i--){
		s=s&a[i];
	}
	cout<<a[q-1];
	return 0;
}
