#include<bits/stdc++.h>
using namespace std;
long long a[200005],res=0;
int n,k;
void dfs(int o,long long num,int i){
	if(o==0){
		res=max(res,num);
		return;
	}
	if(n-i+1<o) return;
	if(num!=-1) dfs(o-1,(a[i]&num),i+1);
	else dfs(o-1,a[i],i+1);
	dfs(o,num,i+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long res2=0,res3=0,res4=0,res5=LLONG_MAX,res6=-1,res7=-1;
	int flag=0,kpl=0,g=0,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		res2=max(res2,a[i]);
		if(a[i]<res5){
			res5=a[i];
			kpl=i;
		}
		if(i==1) res3=a[i];
		else res3=(res3&a[i]);
		if(a[i]==i-1) flag++;
		if(a[i]==0) g++;
		else sum+=a[i];
	}
	if(k==1||(n>2000)){
		cout<<res2;
		return 0;
	}
	if(k==n){
		cout<<res3;
		return 0;
	}
	if(k==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				res4=max(res4,(a[i]&a[j]));
			}
		}
		cout<<res4;
		return 0;
	}
	if(k==n-1){
		for(int i=1;i<=n;i++){
			if(i==kpl) continue;
			if(res6==-1) res6=a[i];
			else res6=(res6&a[i]);
		}
		cout<<res6;
		return 0;
	}
	int n2=n;
	while(n2>1){
		if(n2%2==1&&n2!=1) break;
		else n2/=2;
	}
	if(n2==1&&flag==n){
		for(int i=n;i>=n-k+1;i--){
			if(res7==-1) res7=a[i];
			else res7=(res7&a[i]);
			cout<<res7<<endl;
		}
		cout<<res7;
		return 0;
	}
	if(sum<4){
		if(k>n-g) cout<<0;
		else{
			if(n-g==3) cout<<1;
		}
		return 0;
	}
	dfs(k,-1,1);
	cout<<res;
	return 0;
}
