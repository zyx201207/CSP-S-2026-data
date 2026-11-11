#include<bits/stdc++.h>
using namespace std;
int a[500007][2],s[500007],ans[500007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out ","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][1];
		if(s[a[i][1]]==0)s[a[i][1]]=i;
		else {
			a[s[a[i][1]]][2]=i;
			s[a[i][1]]=i;
		}
		ans[i]=0;
	}
	for(int i=1;i<=n;i++){	
		int l=i;
		while(l<=n){
			if(a[l][2]!=0){
				l=a[l][2];
			}
			else {
				ans[a[l][1]]++;
				l++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}
