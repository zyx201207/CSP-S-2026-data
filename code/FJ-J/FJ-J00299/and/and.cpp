#include <bits/stdc++.h>
using namespace std;
const int N =2e5+5;
long long a[N];
struct cha{
	long long m;//1的数量
	long long n;//量级
	int num;//第几个
};
cha b[N];
int n,m;
int ans=-1;
bool cmp(cha a,cha b){
	if(a.m!=b.m) return a.m>b.m;
	else return a.n>b.n;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i].num=i;
		int hb=1;
		for(int j=1;j<=30;j++){
			if(a[i]>=hb && a[i]<hb*2){
				b[i].n=j+1;
				b[i].m=a[i]-hb+1;
				break;
			}
			hb*=2;
		}
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=m;i++){
		ans&=a[b[i].num];
	}
	cout<<ans;
	return 0;
}
