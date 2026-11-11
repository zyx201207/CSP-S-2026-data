#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[200005];
long long sa[200005];
char c[200005],sc[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;){
		char p=c[i];
		int x=i+1;
		long long sum=a[i]; 	
		while(c[x]==p && x<=n){
			sum+=a[x];
			x++;
		}
		sa[++cnt]=sum;
		sc[cnt]=p;
		i=x;
	}
	int l=1,r=cnt;
	while(l<r){
		if(sc[l]==sc[r]){
			if(sa[l]>sa[r]){
				r--;
				sa[l]-=sa[r];
			}
			else if(sa[l]<sa[r]){
				l++;
				sa[r]-=sa[l]; 
			}
			else{
				l++,r--;
			}
		}
		else{
			if(sa[l]>sa[r]){
				ans+=sa[r];
				sa[l]-=sa[r];
				r--;
			}
			else if(sa[l]<sa[r]){
				ans+=sa[l];
				sa[r]-=sa[l];
				l++;
			}	
			else if(sa[l]==sa[r]){
				ans+=sa[l];
				l++,r--;
			} 
		}
	}
	cout<<ans;
	return 0;
} 
