#include<bits/stdc++.h>
using namespace std;
long n,m,ans=2147483647L,t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		t=a[i];
		for(int j=i;j<n;j++){
			if(a[j]<a[i]){
				t=a[j];
			}
		}
		b.push_back(t);
	}
	for(int i=n-1;i>=n-m;i++){
		ans&=b[i];
	}
	printf("%l",ans);
	return 0;
}
