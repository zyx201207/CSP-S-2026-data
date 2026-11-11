#include<bits/stdc++.h>
using namespace std;
int a[200005];
//long long yu(long long a,long long b){
//	int x[25],y[25];
//	int lenx=0,leny=0;
//	stack<int>c;
//	stack<int>d;
//	while(a>0){
//		if(a%2==0){
//			c.push(0);
//			a=a/2;
//		}else{
//			c.push(1);
//			a=a/2;
//		}
//	}
//	while(b>0){
//		if(a%2==0){
//			d.push(0);
//			b=b/2;
//		}else{
//			d.push(1);
//			b=b/2;
//		}
//	}
//	while(c.empty()){
//		lenx++;
//		x[lenx]=c.top();
//		c.pop();
//	}
//	while(d.empty()){
//		leny++;
//		y[leny]=d.top();
//		d.pop();
//	}
//	int len=min(lenx,leny);
//	int ans[25];
//	for(int i=0;i<len;i++){
//		if(x[lenx-i]==1&&y[leny-i]==1){
//			ans[len-i]=1;
//		}else{
//			ans[len-i]=0
//		}
//	}
//}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	return 0;
}

