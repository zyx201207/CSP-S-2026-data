#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200101],ans,t[101];
struct node{
	int id,s,ans;
}two[101];
void totwo(int n){
	int i=1;
	while(n!=0){
		two[i].s+=n%2;
		n/=2;
		i++;
	}
}
bool cmp(node x,node y){
	return x.id>y.id;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=101;i++)two[i].id=i-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		totwo(a[i]);
	}
//	for(int i=1;i<=101;i++){
//		two[i].ans=pow(2,two[i].id-1);
//	}
	sort(two+1,two+100,cmp);
//	for(int i=1;i<=100;i++){
//		cout<<two[i].id<<" "<<two[i].s<<endl;
//	}
	for(int i=1;i<=n;i++){
		if(two[i].s>=m){
			ans+=pow(2,two[i].id);
			//cout<<i<<" "<<ans<<"\n";
		}
	}
	cout<<ans;
	return 0;
}

