#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005],lin[100005],cnt[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=j+1;i<=n;i++){
			lin[i]=a[i];
			if(b[lin[i]]==1){
				bool z=0;
				for(int l=i-1;l>=j+1&&z==0;j--){
					if(lin[l]==i&&z==0){
						lin[l]=0;
						z=1;
					}else if(z==0){
						lin[l]=0;
					}
				}
			}else{
				b[lin[i]]=1;
			}
			
		}
		for(int h=1;h<=n;h++){
			cnt[lin[h]]++;
		}
		cout<<"a";
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
