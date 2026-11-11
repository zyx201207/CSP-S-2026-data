#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[1000005];
int a[1000005];
bool book [1000001];
int q=0;
void fn(int x){
	for(int i=x;i<=n;i++){
		a[++q]=num[i];
		for(int j=2;j<=q;j++){
			if(a[j]==a[i] && book[j]!=1){
				for(int k=1;k<=j;k++){
					book[k]=1;
					a[j]=a[q];
					q--;
					a[q]=0;
				}
			}
		}
	}
	int ans=0;
	for(int i=x;i<=n;i++){
		if(a[i] ==x && book[i]!=1)ans++;
	}
	cout<<ans<<' ';
	q=0;
	for(int i=1;i<=n;i++){
		book[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=m;i++){
		fn(i);
	}
	return 0;
}
