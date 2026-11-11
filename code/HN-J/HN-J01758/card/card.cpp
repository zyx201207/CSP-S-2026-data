#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], ans[500005], s[5000005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	s[i]=0;
	}
	for(int i=1;i<=m;i++)ans[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s[j]=a[j];
			for(int k=i;k<=j-1;k++){
				if(s[k]==a[j]){
					for(int l=k;l<=j-1;l++){
						s[l]=0;
					}
					break;
			    }
			}
		}
		for(int x=1;x<=n;x++){
			if(s[x]!=0)ans[s[x]]++;
	   }
		for(int j=1;j<=n;j++){
			s[j]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
