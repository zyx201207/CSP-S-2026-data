#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500056],s[500056],ans[10056];
void card(int b){
	for(int i=1;i<=n;i++) s[i]=0;
	for(int i=b;i<=n;i++){
		s[i]=a[i];
		for(int j=1;j<=i;j++){
			if(s[j]==s[i]){
				for(int k=j;k<=i;k++) s[k]=0;
				s[j]=a[i];
				break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=b;j<=n;j++){
			if(s[j]==i) ans[i]++;
		}
	}
	if(b<n) card(b+1);
	else return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	card(1);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
