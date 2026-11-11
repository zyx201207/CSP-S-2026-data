#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
long long cnt;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			long long c=a[i];
			for(int k=0;k<m-1;k++){
				c=c&a[j+k];
				//cout<<c<<' ';
			}
		    if(c>=cnt) cnt=c;
	    }
	}
	cout<<cnt;
	return 0;
} 
