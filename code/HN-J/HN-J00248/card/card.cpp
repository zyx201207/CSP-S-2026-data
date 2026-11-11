#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int n,m;
int a[N];
int b[N];
int f[N];
int ans=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(m==1){
		ans = n;
		cout<<ans<<endl;
		return 0;
	}
	if(m==2){
		cout<<n<<" "<<m;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		 	if(a[i]==a[i-2]){
		 		b[i] = a[i-2];
			}
		}
	}
	for(int i=1;i<=n;i++){
		f[b[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}
