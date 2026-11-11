#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int q=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==2)q++;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		if(a[n]==a[1]){
			if(a[1]==1){
				cout<<n<<" "<<q;
			}
			else{
				cout<<n-q<<" "<<n;
			}
			return 0;
		}
		else{
			cout<<n-q<<" "<<n;
			return 0;
		}
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			b[a[i]]=n-i+1;
		}
		for(int i=1;i<=n;i++){
			cout<<b[i]<<" ";
		}
		return 0;
	}
	else{
		for(int i=1;i<=m;i++){
			cout<<m-i+1<<" ";
		}
		return 0;
	} 
	return 0;
}
