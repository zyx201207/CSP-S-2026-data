#include<bits/stdc++.h>
using namespace std;
int a[200005];
struct number{
	int sum;//差值 
	int num;//数位 
	int id;//原值 
}b[200005];
int p[32];
number cont(int a){
	int i=0;
	while(pow(2,i)<=a){
		i++;
	}
	p[i]++;
	return {(pow(2,i)-a),i,a};
}
bool cmp(number a,number b){
	if(a.num==b.num){
		return a.sum<b.sum;
	}
	return a.num>b.num;
}
bool cmp2(number a,number b){
	if(a.sum==b.sum){
		return a.num>b.num;
	}
	return a.sum<b.sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		b[i]=cont(a[i]);
	}
	sort(b+0,b+n,cmp);
	bool find=0;
	int way=0;
	for(int i=31;i>=0;i--){
		if(p[i]>=m){
			find=1;
			way=i;
		} 
	}
	long long ans;
	int strat;
	if(find==1){
		for(int i=0;i<n;i++){
			if(b[i].num==way){
				ans=b[i].id;
				strat=i;
				break;
			}
		}
		for(int i=strat+1;i<strat+m;i++){
			ans&=b[i].id;
		}
		cout<<ans;
	}else{
		sort(b+0,b+n,cmp2);
		ans=b[0].id;
		for(int i=1;i<m;i++){
			ans&=b[i].id;
		}
		cout<<ans;
	}
	return 0;
}
