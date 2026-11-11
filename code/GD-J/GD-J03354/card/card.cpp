#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],t[M],ans[M];
void out(){
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=n,r=n;
	for(;l>=1;l--){
		t[a[l]]++;
		for(int i=l+1;i<=r&&t[a[l]]==2;i++){
			t[a[i]]--;
			a[i]=0;
		}
		for(int i=1;i<=m;i++){
			if(t[i]!=0)ans[i]++;
		}
	}
	out();


	return 0;
} 
