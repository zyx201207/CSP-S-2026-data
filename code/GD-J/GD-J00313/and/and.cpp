#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;long long s,q=0;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	if(n==m){
		s=a[0];
		for(int i=0;i<n;i++)s&=a[i];
		cout<<s;
	}
	else if(m==n-1){
		for(int i=0;i<n;i++){
			if(i==0)s=a[1];
			else s=a[0];
			for(int j=0;j<n;j++){
				if(j!=i)s&=a[j];
			}
			q=max(q,s);
		}
		cout<<q;
	}
	else if(m==1){
		for(int i=0;i<n;i++)q=max(q,a[i]);
		cout<<q;
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				q=max(q,a[i]&a[j]);
			}
		}
		cout<<q;
	}
	else if(m==3){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				for(int x=0;x<j;x++)q=max(q,a[i]&a[j]&a[x]);
			}
		}
		cout<<q;
	}
	else if(m==4){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				for(int x=0;x<j;x++)for(int y=0;y<j;y++)q=max(q,a[i]&a[j]&a[x]&a[y]);
			}
		}
		cout<<q;
	}
	else cout<<1;
}
