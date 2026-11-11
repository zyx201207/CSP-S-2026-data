#include<bits/stdc++.h>
using namespace std;
long long n,m;long long a[200010];
long long aaa(long long x,long long y){
	long long maxn;
	if(y>=1){
		for(long long i=x+1;i<=n;i++){
			if(y-1==0)return a[i];
			else{
				long long num=a[i]&aaa(i,y-1);
			maxn=max(num,maxn);
			}
			
		}
		
	}
	return maxn;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}		
	cout<<aaa(0,m);
	return 0;
} 

