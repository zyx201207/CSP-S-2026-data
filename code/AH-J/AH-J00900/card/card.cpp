#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long cnt,pos;
}x[300010];
long long n,m,a[500010],ans[300010],t;
stack<long long> b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		while(!b.empty()) b.pop();
		t=0;
		for(int j=i;j<=n;j++){
			if(x[a[j]].cnt!=0){
				while(x[a[j]].cnt!=0){
					t--;
					x[b.top()].cnt--;
					if(x[b.top()].cnt==0) x[b.top()].pos=0;
					b.pop();
				}
			}
			t++;
			b.push(a[j]);
			if(x[a[j]].cnt==0) x[a[j]].pos=t;
			x[a[j]].cnt++;
		}
		while(!b.empty()){
			ans[b.top()]++;
			x[b.top()].cnt=0;
			x[b.top()].pos=0;
			b.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
