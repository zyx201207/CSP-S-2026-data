#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,ans;
}a[200010];
bool cmp(node p1,node p2){
	return p1.ans>p2.ans; 
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max_num=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		int x=a[i].num;
		while(x){
			a[i].ans+=x/2;
			x/=2;
		}
		max_num=max(a[i].num,max_num);
	}
	if(m==1){
		cout<<max_num;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	int x=a[1].num;
	for(int i=2;i<=m;i++) x=x&a[i].num;
	cout<<x;
	return 0;
} 

