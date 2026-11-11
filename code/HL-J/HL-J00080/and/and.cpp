#include<bits/stdc++.h>
using namespace std;
	int main(){
		freopen ("and.in","r",std.in);
		freopen ("and.out","w",std.out);
		int m,n,cnt,s;
		int a[100001];
		cin>>n>>m;
		for(int i=0;i<=n;i++){
			cin>>a[i];
			cnt=a[i]&a[i-1];
			sort(cnt,cnt); 
			s=cnt;
		}
		cout<<s<<endl;
		return 0;
	}
