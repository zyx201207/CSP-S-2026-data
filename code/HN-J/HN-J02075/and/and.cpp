#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int n1;
	int m1[n];
	int max=2;
	for(int i=0;i<n;i++){
		cin>>m1[i];
	}
	sort(m1,m1+n,cmp);
	int c=m1[0];
	int mu=m;
	for(int i=1;i<m;i++){
		if(m1[i]%2==0){
			continue;
		}
	    c=c&m1[i];
	    mu--;
	    if(mu==0){
	       break;
		} 
	}
	cout<<c;
	return 0;
}

