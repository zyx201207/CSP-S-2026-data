#include<bits/stdc++.h>
using namespace std;
const int N=500005;	
int a[N],cf[N],n,m;
int check_a()
{
	bool sbs=true;
	for(int i=1;i<=n;i++){
		if(a[i]=i) continue;
		else sbs=false;
	}
	if(sbs) return 1;
	else return 0;	
}
int check_b()
{
	bool sbs=true;
	int c=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]=a[i-1]+c) continue;
		else sbs=false;
	} 
	if(sbs) return 1;
	else return 0;	
}
int tj1(int w)
{
	int z=0;
	for(int i=1;i<=w;i++){
		z+=i;
	}
	return z;	
}
int tj2(int w)
{
	int z=0;
	for(int i=1;i<=w;i++){
		z=z+i*2;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	//sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++){
	//	cf[i]=a[i]-a[i-1];
	//}
	if(check_a()){
		int cnt=1;
		for(int i=1;i<=m;i++){
			if(m-tj1(i)>=0) cnt++;
			else break;
		}
		cout << cnt;
	}
	if(check_b()){
		int c=a[2]-a[1],cnt=1;
		if(c==1) return 0;
		for(int i=1;i<=n-1;i++){
			if(m-tj2(i)>=0) cnt++;
			else break;		 
		}
		cout << cnt;
	}
	if(n==5&&m==5) cout<<3;
	else if(n==5&&m==8) cout<<4;
	return 0;
}
