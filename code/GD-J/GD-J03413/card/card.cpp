#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[114514],b[114514];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j] && a[i]!=-1 && a[j]!=-1){
				cout<<j<<" ";
				a[i]=a[j]=-1;
				b[a[i]]-=2;
				if(b[a[i]]==0){
					cout<<j<<" ";
				}
				for(int k=i+1;k<j;k++){
					cout<<j-k<<" ";
					b[a[k]]--;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(b[i]==0){
			cout<<n<<" ";
		}
	}
	return  0;
}
