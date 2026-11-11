#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,s;
struct q{
	int num;
	char f;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].f;
		s+=a[i].num;
	}
	int x=1,y=n;
	while(x<y){
		int k=min(a[x].num,a[y].num);
		if(a[x].f!=a[y].f){
			ans+=k;
		}
		a[x].num-=k;
		a[y].num-=k;
		if(a[x].num<=0)x++;
		if(a[y].num<=0)y--;
		s-=2*k;
	}
	cout<<ans;
	return 0;
}
