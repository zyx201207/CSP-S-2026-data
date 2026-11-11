#include<bits/stdc++.h> 
using namespace std;
int a[200005],s[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int tt[100005]={};
	int top;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		top=0;
		for(int i=t;i<=n;i++){
			for(int j=1;j<=top;j++){
				if(s[j]==a[i]){
					top=j-1;	
					break;
				}
			}
			s[++top]=a[i];
		}
		for(int i=1;i<=top;i++){
			int x=s[i];
			tt[x]+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tt[i]<<' ';
	}
	return 0;
}
