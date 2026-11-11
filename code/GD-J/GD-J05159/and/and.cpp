#include<bits/stdc++.h>
using namespace std;
int n,m,a[20010];
int main(){
//	freopen("r","and.in","stdin");
//	freopen("r","and.out","stdout");
	cin>>n>>m;
	long maxn = -1;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		for(int j = n;j>=1;j--){
			int s = a[i]&a[i-j];
			if(s>maxn) maxn = s;
		}
	}
	cout<<maxn;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

