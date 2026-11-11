#include<bits/stdc++.h>
using namespace std;
long long n,m,p,ans;
struct sum{
	int num;
	int k;
};
sum a[200005];
bool cmp(sum x,sum y){
	if(x.num==y.num){
		return x.k>y.k;
	}
	return x.num>y.num;
}
bool cmp1(sum x,sum y){
	return x.k>y.k;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].k;
		int p=a[i].k;
		while(p>=1){
			int flag=p&1;
			if(flag==1){
				a[i].num++;
			}
			p/=2;
		}
//		cout<<a[i].num<<" ";
	}
	sort(a+1,a+1+n,cmp); 
	ans=a[1].k;
	p=1;
	while(true){
		if(p>m)break;
		if((ans&a[p].k)==0){
			break;
		}
		else{
			ans=(ans&a[p].k);
			p++;
		}
		sort(a+1,a+1+n,cmp);
//		cout<<ans<<" ";
	}
	cout<<ans;
	return 0;
}
