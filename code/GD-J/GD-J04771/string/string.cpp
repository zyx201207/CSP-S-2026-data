#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N=2e5+10;
ll n;
char c[N];
ll num[N],ans;
void sos(int x,int y){
	//测试 
	//cout<<x<<' '<<y<<endl;
	if(x>=y){
		return ;
	}
//	for(int i=1;i<=n;i++){
//		cout<<num[i]<<' ';
//	}cout<<endl;
	
	ll k=min(num[x],num[y]);
	if(c[x]==c[y]){
		num[x]-=k;
		num[y]-=k;
	}
	else{
		num[x]-=k;
		num[y]-=k;
		ans+=k;
	}
	if(num[x]==0)x++;
	if(num[y]==0)y--;//一直扣 
	sos(x,y);
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){		
		cin>>num[i];
		cin>>c[i];
	}
//	for(int i=1;i<=n;i++) {
//		cout<<num[i]<<' ';
//	}
	sos(1,n);//为a[i] 的总体 
	cout<<ans;
	return 0;
}
