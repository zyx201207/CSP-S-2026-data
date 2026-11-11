//GZ-J00166  遵义市第19中学 张铭泽
#include<bits/stdc++.h>
using namespace std;

int a[200005],b[200005];
int cmp(int x,int y){
	return x>y;
}
int main() {
	freopen("and.in","v",stdin);
	freopen("and.out","w",stdout);
    int n,m,sum;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	for(int i=1;i<=m;i++){
		b[i]=a[i];
		sum&=b[i];	
	}
	cout<<sum;
	return 0;
}
