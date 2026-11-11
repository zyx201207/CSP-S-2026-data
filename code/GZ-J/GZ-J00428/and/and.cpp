//侯欣言  GZ-J00428 兴义市弘毅中学
#include <bits/stdc++.h>
using namespace std;
long long m,n;
long long sum=0;
long long shu[1000000];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>shu[i];
	}
	sort(shu,shu+n);
	cout<<shu[m-1];
	/*5 3
31 3 1 15 7*/
	
	return 0;
}

