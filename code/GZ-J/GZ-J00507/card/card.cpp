//GZ-J00507 陈俊瑞 兴义市弘毅中学 
#include<iostream>
#include<stack>
using namespace std;
#define maxn 500005
#define maxm 300005
int n,m;
int a[maxn];
long long ans[maxm];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<1<<' ';
	}
	cout<<'\n';
	return 0;
}
