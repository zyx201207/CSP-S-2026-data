#include <bits/stdc++.h>
using namespace std;
struct mn{
	int count_one_n;
	int first_n;
};
int a[200005];
mn maxnum[200005];
int n_in_2[35];
int change(int n){
	int num=0,ret=0;
	if(n=0) return 0;
	for(int i=0;n>0;i++){
		n_in_2[i]=n%2;
		n/=2;
		num++;
	}for(int i=num-1;i>=0;i++){
		ret*=10;
		ret+=n_in_2[i];
	}return ret;
}
int count_one(int n){
	int n_2=change(n);
	int cnt=0;
	while(n_2>0){
		if(n_2%10==1) cnt++;
		n_2/=10;
	}
}
bool cmp(mn a,mn b){
	return a.count_one_n>b.count_one_n;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxm=0;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
		maxnum[i].count_one_n=count_one(a[i]);
		maxnum[i].first_n=a[i];
	}
	sort(maxnum+1,maxnum+n+1,cmp);
	cout<<maxnum[0].first_n<<maxnum[1].first_n<<maxnum[2].first_n;
	return 0;
}
