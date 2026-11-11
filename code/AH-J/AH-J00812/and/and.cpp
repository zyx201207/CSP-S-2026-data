#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int ans[40],fg;
bool qwq[200005];
struct node{
	int t_;
	int a[40];
}t2[200005];
void i_to2(int op,int id){
	if(op==0){
		t2[id].t_=31;
		for(int i=1;i<=31;i++)
			t2[id].a[i]=0;
		return;
	}
	while(op){
		t2[id].t_++;
		t2[id].a[t2[id].t_]=op%2;
		op/=2;
	}
	while(t2[id].t_<31){
		t2[id].t_++;
		t2[id].a[t2[id].t_]=0;
	}
	for(int i=1,j=31;i<j;i++,j--)
		swap(t2[id].a[i],t2[id].a[j]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(qwq,1,sizeof qwq);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		i_to2(a[i],i);
	for(fg=1;fg<=31;fg++){
		int sum=0;
		for(int i=1;i<=n;i++)
			if(t2[i].a[fg]&&qwq[i]) sum++;
		if(sum<m) ans[fg]=0;
		else{
			ans[fg]=1;
			for(int i=1;i<=n;i++)
				if(!t2[i].a[fg]) qwq[i]=0;
		}
	}
	fg=0;
	for(int i=1;i<=31;i++)
		fg+=ans[i]*(1<<(31-i));
	cout<<fg;
	return 0;
}
