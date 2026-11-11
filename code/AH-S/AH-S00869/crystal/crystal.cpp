#include<bits/stdc++.h>
#define ll long long
#define du double 
using namespace std;
const int M=5e5+5;//最大值 
//1 4 4 8 9
//1 3 0 4 1
//2 4 6 8 10
int a[M],cha[M];
int n;
ll m;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int pd=1;
	cin>>a[1];
	cha[1]=0;
	for(int i=2;i<=n;++i){
		cin>>a[i];
		cha[i]=a[i]-a[i-1];
		if(i>=3&&cha[i]!=cha[i-1])pd=0;
	}
	if(pd){//等差数列  
		int ca=cha[2],end=n;
		ll ans=0;
		for(int i=1;i<=n-1;++i){
			if(ans+=ca*i){
				if(ans>m){
					end=i;
					break;
				}
			}
		}cout<<end;
	}else{
		ll ans=-1;//记录每次末尾的答案，再进行累加 
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i){
			//目标为a[i]，向前查找符合条件的数 
			int id=i;
			ll dx=0,ji=0;
			while(id>=1&&dx+cha[id]<=m){
				dx+=cha[id];
				id--;
				ji++;
			}ans=max(ans,ji);
		}cout<<ans;
	}
	return 0;
}
