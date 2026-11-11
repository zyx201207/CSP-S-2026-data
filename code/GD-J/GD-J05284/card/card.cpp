#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500050],ans[500050];
bool vt[50050];

void f(int k){
	memset(vt,0,sizeof(vt));
	for(int i=k;i<=n;i++){
		if(!vt[a[i]]){
			vt[a[i]]=1;
		}
		else{
			for(int j=i-1;j>=k;j--){
				if(a[j] == a[i])break;
				else{
					vt[a[j]] = 0;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		ans[i] += vt[i];
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
