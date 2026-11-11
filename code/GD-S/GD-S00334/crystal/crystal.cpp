#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
int cnt[500010];

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[n];
	}
	
	int k=1;
	while(m){
		while(b[k]<b[k+1] && m){
			for(int i=1;i<=k;i++){
				b[i]++;
				if(m>0){
					m--;	
				}
				else{
					break;
				}
					
			}
			
		}
		k++;
	}
	int mx=b[1];
	
	
	for(int i=1;i<=n;i++){
		cnt[abs(b[i])]++;
	}
	int max=cnt[1];
	
	for(int i=2;i<=n;i++){
		if(max<cnt[i]){
			max=cnt[i];
		}
	}
	
	cout << max;
	
	return 0;
} 
