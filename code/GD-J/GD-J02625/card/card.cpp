#include<bits/stdc++.h>
using namespace std;
int a[5000010];
int sum[3000010];
int cnt[3000010];
int b[3000010];
bool gou[3000010];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m,k;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
		cnt[a[i]]++;
		b[a[i]]++;
	}
	for(int i=0;i<n;i++){
		int line=i;
		for(int k=1;k<=m;k++){
			gou[k]=false;
		}
		for(int i=1;i<=m;i++){
			b[i]=cnt[i];
		}
		for(int j=i;j<n;j++){
			if(j==i){
				gou[a[j]]=true;
				b[a[j]]--;
			}
			else if(j==n-1){
				gou[a[j]]=true;
			}
			else{
				if(gou[a[j]]==true){
					b[a[j]]--;
					line = j;
					continue;
				}
				gou[a[j]]=true;				
				b[a[j]]--;
				for(int p=j-1;p>=line;p--){
					if(b[a[p]]!=0){
						gou[a[j]]=false;
						break;
					}
				}
				
			}
		}
		
		for(int x=1;x<=m;x++){
			if(gou[x]==true){
				sum[x]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << sum[i] << " ";
	}
	return 0;
}
