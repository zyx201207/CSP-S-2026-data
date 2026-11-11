#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;

struct unknown{
	int num;
	char ch;
}a[MAXN]; 
int n,ans=0;
int tot;

void dfs(int l,int r,int left_idx,int right_idx){ //lr当前一侧的的还剩几个 ，_idx当前遍历到的下标 
	if(left_idx>=right_idx){
		return ;
	}
	if(a[left_idx].ch==a[right_idx].ch){
		if(l>r){
			l-=r;
			right_idx--;
			r=a[right_idx].num;
		}
		else if(l==r){
			right_idx--;
			left_idx++;
			r=a[right_idx].num;
			l=a[left_idx].num;
		}
		else{
			r-=l;
			left_idx++;
			l=a[left_idx].num;
		}
		dfs(l,r,left_idx,right_idx);
	}
	else{
		if(l>r){
			l-=r;
			ans+=r;
			right_idx--;
			r=a[right_idx].num;
		}
		else if(l==r){
			right_idx--;
			left_idx++;
			ans+=r;
			r=a[right_idx].num;
			l=a[left_idx].num;
		}
		else{
			r-=l;
			ans+=l;
			left_idx++;
			l=a[left_idx].num;
		}
		dfs(l,r,left_idx,right_idx);
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].ch;
	}
	dfs(a[1].num,a[n].num,1,n);
	cout<<ans;
	return 0;
	//好难！！！ 10:12 
}
