#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200005];
long long pow2[35];
//long long ans[200005];
bool v[200005];
bool cmp(long long x,long long y){
	return x>y;
}
long long ans1;
void dfs(int num,long long sum,int cnt){
	if(num>n){
		if(sum!=INT_MAX&&cnt==m){
			ans1=max(ans1,sum);
		}
		return;
	}
	v[num]=1;
	dfs(num+1,sum&a[num],cnt+1);
	v[num]=0;
	dfs(num+1,sum,cnt);
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(n<=20){
		dfs(1,INT_MAX,0);
	}else{
		ans1=a[1]&a[2];
		for(int i=3;i<=m;i++){
			ans1=ans1&a[i];
		}
	}
	cout<<ans1;
//	pow2[0]=1;
//	for(int i=1;i<=33;i++){
//		pow2[i]=2*pow[i-1];
//	}
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	sort(a+1,a+1+n,cmp);
//	if(m==1){
//		cout<<a[1];
//		return 0;
//	}
//	bool f=false;
//	int idx=1;
//	for(int i=1;i<=n;i++){
//		f=false;
//		for(int j=1;j<=32;j++){
//			if(a[i]+1==pow2[j]){
//				f=true;
//				break;
//			}
//		}
//		if(f){
//			ans[idx]=i;
//			idx++;
//		}
//		
//		if(idx>m){
//			break;
//		}
//	} 
	
	return 0;
	
} 
