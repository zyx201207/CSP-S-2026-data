#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	long long a[99999];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int p=0;
	for(int i=0;i<n;i++){
		p=0;
		for(int j=0;j<n;j++){	
			if(a[i]==a[j]){
				p++;
				if(p==2){
					cout<<a[i];
					return 0;
				}
			}
		}
	}
	return 0;
}