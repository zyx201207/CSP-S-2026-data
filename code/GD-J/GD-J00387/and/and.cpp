#include<bits/stdc++.h>
using namespace std;
long long a[200001],b[200001],n,m,s=-1;
bool v[200001];
/*
5 3
31 3 1 15 7
*/
/*
4 2
3 15 12 12
*/
//create
//CCF shao ye ji zhu wo
void f(int x){
	if(x>m){
		long long ls=a[b[1]];
		for(int i=2;i<=m;i++)ls&=a[b[i]];
		s=max(s,ls);
		return;
	}
	for(int i=x;i<=n;i++)if(!v[i]){
		b[x]=i;v[i]=1;
		f(x+1);v[i]=0;
	}
	return;
}
bool f2(long long x,long long y){return x>y;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,f2);
	f(1);//no sir
	cout<<s;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//哦不不不不，要开始神秘暴力了，我无疑是愤怒的 
//10:37 第一版暴力也是搓出来了 
//还好检查了，差点悲剧 
//11:38不会做了
//11:48 还好检查了，差点悲剧*2 
//11:50 最后的10min 
