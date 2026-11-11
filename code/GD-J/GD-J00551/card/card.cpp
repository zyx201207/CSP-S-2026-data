#include<bits/stdc++.h>
using namespace std;
int a[114514];int s[114514];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=0;k<n;k++){
	for(int j=0;j<n;j++){
	for(int i=0;i<m;i++){
			if(s[j]==0){
				s[j]==a[i];
			}
			else{
				for(int i=0;i<m;i++){
					s[i]=0;
			}
		}
		
		}
	}
}
for(int i=1;i<=n;i++){
	cout<<a[i];
}
}
