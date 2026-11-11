#include<bits/stdc++.h>
using namespace std;
int  n,m,s,a[100010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+n,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i]+1==a[i+1]){
				a[i]++;
				m--;
			}else{
				continue;
			}
		}
	for(int i=1;i<=n;i++){
		if(a[i]=a[i+1]){
			s++;
			continue;
		}else {
			continue;
		} 
	} 
	cout<<s;
	return 0;
} 
