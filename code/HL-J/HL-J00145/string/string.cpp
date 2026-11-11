#include<bits/stdc++.h>
using namespace std;
string s;
char b[200010];
int n;
long long a[200010],cnt,l,r,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	r=n-l-1;
	while(l<r){
		long long minn=min(a[l],a[r]);
		if(b[l]!=b[r]){
			cnt+=minn;
		}
		a[r]-=minn;
		a[l]-=minn;
		if(a[l]==0) l++;
		if(a[r]==0)r--;
	}
	cout<<cnt;
	return 0;
}
/* 3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/