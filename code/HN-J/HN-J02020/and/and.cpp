#include<bits/stdc++.h>
using namespace std;

int a[10010];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int i;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int j;
	int c=-1;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				if(a[i]>=c){
					c=a[i];
				}
			}
		}
	}
	cout<<c;
	
	return 0;
}
