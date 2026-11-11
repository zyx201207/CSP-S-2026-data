#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct www{
	int x;
	char c;
};
www a[999999];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long num=0;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].c;
		num+=a[i].x ;
	}
	int w=ceil(n/2);
	int l=1,r=n;
	long long ans=0;
	while(l<=r){
		if(a[l].c ==a[r].c ){
			if(a[l].x >a[r].x){
				a[l].x -=a[r--].x;
				continue; 
			}
			else if(a[l].x ==a[r].x ){
				++l,--r;
				continue;
			}
			else{
				a[r].x -=a[l++].x ;
				continue;
			}
		}
		else{
			if(a[l].x >a[r].x){
				a[l].x -=a[r].x;
				ans+=a[r--].x;
				continue; 
			}
			else if(a[l].x ==a[r].x ){
				l,--r;
				ans+=a[l++].x ;
				continue;
			}
			else{
				a[r].x -=a[l].x ;
				ans+=a[l++].x ;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
