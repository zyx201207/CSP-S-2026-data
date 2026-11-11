#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
struct node{
	int zhi,cha;
}a[N];
bool cmp(node b,node c){
	return b.zhi<c.zhi;
}
bool f(int i){
	int sum=0;
	for(int j=1;j<i;j++){
		sum+=a[i].zhi-a[j].zhi;
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].zhi;
		a[0].zhi=a[1].zhi;
		a[i].cha=a[i].zhi-a[i-1].zhi+a[i-1].cha;
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i].cha>= m){	
			if(f(i)<=m){
				ans=i;
				break;
			}else{
				ans=i-1;
			}
		}
	}
	cout<<ans-1;
	return 0;
}

