#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
//int a[N]={0};
//int ch[N]={0};
struct node{
	int num;
	int co1;
}a[N];
bool cmp(node t1,node t2){
	return t1.co1>=t2.co1;
}
int main(){
		freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	int ma=-1,ma1a=-1;
	int k=1;
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		a[i].num=c;
		int co=0;
		while(c!=1){
			if(c%2)co++;
			c>>=1;
		}
		co++;
		a[i].co1=co;
	}
	sort(a+1,a+1+n,cmp);
	long long ans=pow(2,30)-1;
	for(int i=1;i<=m;i++){
		ans&=a[i].num;
//	cout<<a[i]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
