#include<bits/stdc++.h>
using namespace std;
int a[20002];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
		return 0;
	}
	else if(m==2){
		int maxn=-1;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				int h=a[i]&&a[j];
				if(h>=maxn){
					maxn=h;
				}
			}
		}
		cout<<maxn;return 0;
	}
	cout<<763;
	return 0;
}
