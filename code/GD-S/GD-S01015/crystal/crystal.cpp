#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("cry stal.out","w",stdout);
	long long n,q=0;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		long long k,l=0,q1=1;
		k=a[i];
		int e=i-1;
		while(e>0 && l<=m){
			k--;
			if(k==a[e]){
				q1++;
				e--;
			}
			l++;
		}
		q=max(q,q1);
	}
	cout<<q;	
			   
	
		
	
	
	
	
	return 0;
}
