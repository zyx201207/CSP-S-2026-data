 #include<bits/stdc++.h>
 using namespace std;
 int a[10000005];
 int main(){
 	freopen("std.in","r",stdin);
	freopen("std.out","w",stdout); 
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[n];
 	return 0;
 } 
