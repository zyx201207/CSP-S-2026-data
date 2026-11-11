#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define LL long long
using namespace std;
const int N=5e5+10;
const int Inf=0x3f3f3f3f;
LL n,m,a[N],k1,anss,sum,ans1,ans,k,mid,ke[N]; 
queue<LL> duan;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	mid=a[1];//a[n/2];
	ans=1;
	for(int i=2;i<=n;i++){
		LL jia=(a[i]-mid)*(i-1);
		ke[i]=jia+ke[i-1];
		if(a[i]!=a[i-1]){
			duan.push(i);
			k1+=jia;
			k+=jia;
			mid=a[i];
 	}
//		cout<<a[i]<<' ';
//		if(a[i]>mid){
//		}else k+=mid-a[i];
		if(k>m){
//			cout<<duan.front()<<' ';
			anss=max(anss,ans);
			ans=ans1-duan.front();
			k=k1-ke[duan.front()];
			duan.pop();
		}
		ans1++;
		ans++;
	}cout<<anss;
	return 0;
}

