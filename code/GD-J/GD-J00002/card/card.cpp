#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],an[300005],x,y;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(a[x]==0){
			a[x]=i; 
		}else{
			for(int k=1;k<=m;k++){
				if(a[k]==0 || a[k]<=a[x]) continue;
				an[k]+=i-a[k];
				a[k]=0;
			}
			a[x]=i;
			
	}
	}
	for(int i=1;i<=m;i++){
		if(a[i]==n){
			cout<<n<<" ";
			continue;
		}
		cout<<a[i]-an[i]<<" ";
	}
	return 0;
}
