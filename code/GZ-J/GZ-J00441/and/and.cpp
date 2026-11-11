//GZ-J00441   遵义市第十二中学   杜奕辰
#include <bits/stdc++.h>
using namespace std;
long long a[200005],r[200005];
bool cmp(long long x,long long y){
	return x>y;
}
void er(int x){
	int i=0;
	while(x!=0){
		r[i]=x%2;
		x/=2;
		i++;
	}
}
int e;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=-2e9;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+0,a+n,cmp);
	
	return 0;
}

