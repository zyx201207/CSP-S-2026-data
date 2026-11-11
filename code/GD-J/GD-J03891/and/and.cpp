#include <bits/stdc++.h>
using namespace std;
int n,m,a[100000],d,cnt=1,l=1;
bool flag = true;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 2;i<=n;i++){
		if(a[i]>a[i-1]){
			d=a[i-1];
			a[i-1]=a[i];
			a[i]=d;
		}
	}
	for(int i = 1;i<=n;i++){
		if(a[i]==a[i-1]){
			cnt++;
			if(cnt>=m){
				cout<<a[i];
				flag = false;
			}
		}
		else{
			cnt = 1;
		}
	}
	if(flag){
		cout<<a[4];
	}
	return 0;
}
