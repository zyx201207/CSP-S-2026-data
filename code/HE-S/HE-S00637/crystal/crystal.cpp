#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int p=0;
bool check(int x){
//	int uuu=0;
//	for(int j=1;j<=n-x+;j++){
//		
//	}
//	for(int i=2;i<=x;i++){
//		uuu+=(abs(a[i]-a[i-1]))*(x-1);
//	}
//	if(uuu<=m)return 1;
//	return 0;

	int uu=1e16;
	for(int i=1;i<=n-x+1;i++){
		int o=a[i+x-1];
		int sum=0;
		bool flag=1;
		for(int j=i;j<x+i-1;j++){
			sum+=o-a[j];
			if(sum>m){
				flag=0;
				break;
			}
		}
		if(flag)uu=min(uu,sum); 
	}
	if(uu==1e16)return 0;
	else return 1;

//	int uu=1e16;
//	int o=a[p+x-1];
//		int sum=0;
//		bool flag=1;
//		for(int j=p;j<x+p-1;j++){
//			sum+=o-a[j];
//			if(sum>m){
//				flag=0;
//				return 0;
//			}
//		}
//		if(flag)uu=min(uu,sum); 
//	if(uu==1e16)return 0;
//	else return 1;
}
bool check2(int x,int cha){
	long long pp=0;
	for(int i=1;i<=x;i++){
		pp+=i;
	}
	int sq=x*x;
	unsigned long long ppp=cha*(sq-pp);
	if(ppp>m)return 0;
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool flagi=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)flagi=0;
	}
	sort(a+1,a+n+1);
	//1 1 1 1 0 0 0 0 0 
	//9 9
	//1 2 3 4 5 6 7 8 9 
	//2 2 3 4 5 6 7 8 9 --1   +1代价：1 1  (2)
	//3 3 3 4 5 6 7 8 9 --2   +1代价：2 3  (3)
	//4 4 4 4 5 6 7 8 9 --3   +1代价：3 6  (4)
	//4 5 5 5 5 6 7 8 9 --3   +1代价：4 10 (5)
	//5:3 6:4 9:4
	//1 3 6 10 15 21 28 36 45
	
	
//	if(flagi==1){
//		int u=0;
//		int uu=0;
//		while(u<m){
//			uu++;
//			u+=uu;
//		}
//		if(u>m)cout<<min(uu-1,n);
//		else cout<<min(uu,n);
//		return 0;
//	}
    int uo=1e12;
    for(int i=1;i<=n-m+1;i++){
    	int ooo=0;
	    for(int j=i+1;j<=m+i-1;j++){
	    	ooo+=a[i]-a[i-1];
		}
		if(uo>ooo){
		    uo=ooo;
			p=i;	
		}
    }
	bool flag=1;
	int u=abs(a[2]-a[1]);
	for(int i=3;i<=n;i++){
		if(abs(a[i]-a[i-1])!=u){
			flag=0;
		}
	}
	//4 12
	//1 3 5 7 
	//3 3 5 7 --2
	//5 5 5 7 --6
	//7            7           7           7 --12
	//(n-1)*cha   (n-2)*cha   ...        (n-n)*cha
	//cha*(n*n-(1+2+3+4+5+......+n))
	
	//5 5 
	//1 2 4 8 9 
	// 1 2 4 1
	//2 2 4 8 9 --1 2 +(a[2]-a[1])*(x-1) 1
	//4 4 4 8 9 --5 3 +(a[3]-a[2])*(x-1) 4
	//8 8 8 8 9 --17 4 +(a[x]-a[x-1])*(x-1)
	//9 9 9 9 9 --  
	//2~x 
	if(flag==1 || flagi==1){
		int l=0,r=n;
		while(l<r){
			int mid=(l+r+1)/2;
			if(check2(mid,u)){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		cout<<l<<endl;
		return 0;
	}
	int l=0,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l<<endl;
	return 0;
} 
