#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

int n,m;
int a[N];
bool s[N];
long long ans;

int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p=n;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=i+n;j++){
			if(j>n){
				for(int k=j-n;k>=1;k--){
					if(a[k]==a[j-n]){
						for(int l=k;l>=j-1;l++){
							s[l]=1;
						}
					}
					if(k==1){
						k=n; 
					}
					if(k==i){
						break;
					}
				}//ÅÐ¶Ï+ÒÆ³ý
			}else{
				for(int k=j;k>=i;k--){
					if(a[k]==a[j]){
						for(int l=k;l>=j-1;l++){
							s[l]=1;
						}
					}
				}//ÅÐ¶Ï+ÒÆ³ý 
			}
		}
		for(int p=1;p<=n;p++){
			if(s[p]!=1&&a[p]==i){
				ans++;
			}
		}
		cout<<ans<<" ";
		for(int q=1;q<=n;q++){
			s[q]=0;
		}
	}
	return 0;
}

