#include<bits/stdc++.h>
using namespace std;
struct chuan{
};
int a[200005];
long long n,m,ans;
bool qwe(int q,int w){
	return q>w;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,qwe);
	ans=a[0];
	for(int i=1;i<m;i++){
		ans&=a[1];
	}
	cout<<ans;
	return 0;
}
