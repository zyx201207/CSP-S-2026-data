#include<bits/stdc++.h>
using namespace std;
long long n,m,aa,poww[35],cnt,cntt,min_cnt,ans,wei[35];
string num[200010];
struct node{
	string num;
	int cnt_one,vis;
}a[200010];
void add_a(){
	cntt=30;
	long long aaa=aa;
	while(aaa){
		if(aaa%2==1) a[cnt].num[cntt]='1',a[cnt].cnt_one++,wei[cntt]++;
		aaa=aaa/2;
		cntt--;
	}
	min_cnt=min(min_cnt,cntt);
	cnt++;
}
bool cmp(node node1,node node2){
	if(node1.cnt_one!=node2.cnt_one) return node1.cnt_one>node2.cnt_one;
	else return node1.num>node2.num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	poww[30]=1;cnt=1;min_cnt=100;
	for(int i=1;i<=200000;i++){
		a[i].num="0000000000000000000000000000000";
	}
	for(int i=29;i>=1;i--) poww[i]=poww[i+1]*2;
	for(int i=1;i<=n;i++){
		cin>>aa;
		add_a();
	}
	min_cnt=min_cnt+1;
	sort(a+1,a+n+1,cmp);
	for(int i=min_cnt;i<=30;i++){
		int tmp=1;
		for(int j=1;j<=m;j++){
			if(a[j].num[i]=='0'){
				tmp=0;
				break;
			}
		}
		if(tmp) ans+=poww[i];
	}
	cout<<ans;
	return 0;
}
