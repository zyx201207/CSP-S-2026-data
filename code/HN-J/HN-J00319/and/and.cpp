#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long a,c;
	cin>>a>>c;
	long long b[a];
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	sort(b+0,b+a);
	long long ywh=b[a-1];
	for(int i=a-1;i>=c-1;i--){
		ywh=ywh&b[i];
	}
	cout<<ywh;
	return 0;
}
