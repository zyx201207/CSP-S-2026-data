#include<bits/stdc++.h>
using namespace std;	
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	int n,m;
	cin>>n>>m;
	int s[n+1],a[n+1];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int ans=0;
	for(int i=1,j=n;i<=n,j>=1;i++){
		if(s[i]!=s[j])j--;
		else for(int q=i;q<=j;q++){
			a[q]=s[q];
		}
		if(s[j+1]==1)cout<<++ans;
		ans++;
	}
	cout<<1<<" "<<ans;
	return 0;
}
