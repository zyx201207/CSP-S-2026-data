#include<bits/stdc++.h>
using namespace std;
string s;
int n;
//int t[27];
/*
3
2 a
2 b
1 c
change 1
---
1 a
2 b
--
1 b
change 2
aabbc

4
5 a
6 c
8 h
9 a
aaaaa cccc cc hhhhhh hh aaaa aaaaa
---
6 c
8 h
4 a
change=0
---
2 c
8 h
change=4
---
6 h
change=6
*/
long long cnt=0;
long long a[100010];
char c[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long ai;char ci;
		scanf("%lld %c",&ai,&ci);
		//c[i]=ci;
		if(c[cnt]==ci){
			a[cnt]+=ai;
		}else{
			cnt++;
			a[cnt]+=ai;
			c[cnt]=ci;
		}
		//cout<<"inputing"<<i<<endl;
		//reverse();
	}
//	cnt=n;
//	for(int i=1;i<=cnt;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=cnt;i++){
//		cout<<c[i]<<" ";
//	}
//	cout<<"\n";
	long long l=1;
	long long r=cnt;
	long long change=0;
	while(l<r){
		//cout<<"l="<<l<<"r="<<r<<"change="<<change<<endl;
//		for(int i=l;i<=r;i++){
//			cout<<a[i]<<" "<<c[i]<<endl;
//		}
//		cout<<"eq="<<change<<endl;
		if(a[l]==a[r]){
			l++;
			r--;
			if(c[l]!=c[r]){
				change+=min(a[l],a[r]);
			}
		}else if(a[l]-a[r]>0){
			if(c[l]!=c[r]){
				change+=min(a[l],a[r]);
			}
			a[l]=a[l]-a[r];
			r--;
			
		}else{
			if(c[l]!=c[r]){
				change+=min(a[l],a[r]);
			}
			a[r]=a[r]-a[l];
			l++;
		}
	}
	cout<<change;
	return 0;
}
/*

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
//////
10 200 10 20
v   a  v  p
关闭压缩，加快了读入，但是……


*/



