#include<bits/stdc++.h>
using namespace std;
struck number{
	int s;
	int e[10000000005];
}a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].s;
		int cnt=0;
		for(int j=a[i].s;j>=0;j/=2){
			a[i].e[cnt]=j%2;
			cnt++;
		}
	}
	int b[200005];
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<=(a[i].e).size();j++){
			for(int k=0;k<n;k++){
				cnt++;
			}
		}
	}
	return 0;
}
