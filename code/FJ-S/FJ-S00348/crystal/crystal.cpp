#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
bool cs16=1;
int a[500001],xx[500001];
inline int rd(){
	int k=0,q=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')q=-1;
		c=getchar();
	}while(isdigit(c)){
		k*=10,k+=c-48,c=getchar();
	}return k*q;
}bool check(int mid){
	int cnt=0,can_=0;
	for(int i=1;mid+i-1<=n;++i){
		if((a[i+mid-1]-a[i])*mid<=m)return 1;
		for(int j=i;j<=i+mid-1;++j){
			cnt+=a[i+mid-1]-a[j];
			if(cnt>m)break;
		}
		if(cnt<=m)return 1;
		cnt=0;
	}return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=n;++i){
		a[i]=rd();
	}sort(a+1,a+n+1);
	int dc=a[n]-a[n-1],jl=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=dc)cs16=0;
	}
	if(cs16){
		for(int i=1;i<=n;i++){
			xx[i]=xx[i-1]+i;
		}for(int i=1;i<=n;i++){
			xx[i]*=dc;
		}
		for(int i=1;i<=n;i++){
			if(xx[i]<=m&&xx[i+1]>m){
				cout<<i;
				return 0;
			}
		}
	}
	int lt=1,rt=n;
	while(lt<rt){
		int mid=(lt+rt)>>1;
		if(lt==rt-1){
			if(check(rt)){
				lt=rt;
			}break;
		}
		if(check(mid)){
			lt=mid;
		}else{
			rt=mid-1;
		}
	}cout<<lt;
	return 0;
}