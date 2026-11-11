#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m,ans,cq,q[MAXN];
struct NODE{
	string s;
	int num;
};
NODE a[MAXN];
bool cmp(NODE x,NODE y){
	return x.s>y.s;
}
void add(int id,int x){
	stack<int> stk;
	int bc=x,c=0;
	while (x!=0){
		if (x&1==1){
			stk.push(1);
		}
		else stk.push(0);
		x/=2,c++;
	}
	string ts="";
	for (int i=1;i<=31-c;i++){
		ts+='0';
	}
	while (!stk.empty()){
		int tmp=stk.top();stk.pop();
		ts+=(tmp+'0');
	}
	a[id].s=ts,a[id].num=bc;
}
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int ta;cin>>ta;
		add(i,ta);
	}
	sort(a+1,a+n+1,cmp);
	int l=1;
	for (int i=1;i<=31;i++){
		int cnt=0;
		for (int j=1;j<=n;j++){
			if (a[j].s[i-1]=='1'){
				cnt++;
				if (cnt==1) l=j;
				if (cnt>=m) break;
			}
		}
		if (cnt>=m){
			ans+=1<<(31-i);
			q[++cq]=i;
		}
	}
	cout<<ans;
	return 0;
}

/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/


