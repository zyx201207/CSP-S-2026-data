#include<bits/stdc++.h>
using namespace std;
int n,m,sum,to,tal,ol;
int a[500050],b[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		sum+=a[i];
	}
	sum = a[n];
	ol = n;

	while(1){
		to = 0;
		tal = 0;

		for(int i = 1;i<=n;i++){
			b[i]=0;
			if(sum>a[i]){
				b[i] = sum-a[i];
			}
		} 
		
		for(int i = 1;i<=n;i++){
			to+=b[i];
			if(to>m){
				break;
			}
			if(b[i]+a[i]==sum){
				tal++;
			}
		}
		
		if(to==m){
			break;
		}
		else if(to>m){
			ol--;
			sum = a[ol];
		}
		
	}
	cout<<tal;
	return 0;
}
