#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
/*
对于元素i：
若其是第一次出现，ans++
否则，略过这个元素到该元素最后一次出现的位置，然后ans为最后出现位置的ans
Trick||Treat!
10 3
3 1 2 1 3 2 3 1 2 1

4 3
1 2 1 3

10 3
3 3 2 1 2 3 1 3 1 3
* 
11 4
1 2 3 2 4 3 2 1 4 3 1
*/
/*struct node{
	int val,idx;
	int rk;
	
};
bool cmp1(node x,node y){
	return x.idx<y.idx;
}
bool cmp2(node x,node y){
	return x.val
}*/

int aannss[300005];
void solve(int k,int cc){
	int add[300005]={};
	int cnt[300005]={};
	int bef[300005]={};
	for(int i=k;i<=n;i++){
		cnt[a[i]]++;
		if(cnt[a[i]]>1){
			//cout<<i<<" "<<a[i]<<" "<<bef[a[i]]<<endl;
			for(int j=bef[a[i]];j<i;j++){
				cnt[a[j]]--;
			}
		}
		bef[a[i]]=i;
	}
	//cout<<k<<" ";
	for(int i=1;i<=m;i++){
		if(cnt[i]){
			add[i]=1;
			//cout<<i<<" ";
		}
		//cout<<add[i]<<" ";
	}
	//cout<<endl;
	for(int i=1;i<=m;i++){
		aannss[i]+=add[i]*cc;
	}
}
int lst[300005];
bool f=1;
int sum[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=0;
		lst[a[i]]=i;
		sum[a[i]]++;
	}
	if(f){//15pts
		int sum=1;
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				cout<<sum<<" ";
			}
			sum++;
		}
		cout<<n;
		return 0;
	}
	//for(int i=1;i<=m;i++){
		//cout<<i<<" "<<lst[i]<<" "<<sum[i]<<endl;
	//}
	for(int i=1;i<=m;i++){
		solve(lst[i],sum[i]);
	}
	for(int i=1;i<=m;i++){
		cout<<aannss[i]<<" ";
	}
	return 0;
}
