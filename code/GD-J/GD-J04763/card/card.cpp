#include<bits/stdc++.h>
using namespace std;
const int N=500050;
const int M=300050;
int l_p[M];
int a[N];
int f[N];
bool b[N];
int pos;
int n,m; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!l_p[a[i]])l_p[a[i]]=i;
		else{
			b[l_p[a[i]]]=1;
			l_p[a[i]]=i;
		}
//		l_p[a[i]]=i;
	}
	priority_queue<int,vector<int>,less<int> >pos;
	pos.push(-1);
	for(int i=1;i<=n;i++){
		while(pos.top()!=-1&&a[pos.top()]==a[i])pos.pop();
		//cout<<i<<","<<pos.top()<<"\n";
		f[i]=pos.top();
		if(b[i])pos.push(i);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i-1;j>=1;j--){
//			if(a[j]==a[i])continue;
//			if(l_p[a[j]]>i)f[i]=j;
//		}
//	}
	for(int i=1;i<=m;i++){
		int p=l_p[i];
		int f_p=f[p];
		if(f_p==-1)cout<<p<<" ";
		else cout<<p-(f_p+1)+1<<" ";
	}
	return 0;
}
