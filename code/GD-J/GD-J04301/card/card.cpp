#include <bits/stdc++.h>
using namespace std;
long long maxa,ans[300005],frist[300005],b[300005],n,x,a[300005],m,sum;

int main(){
	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i= 1;i<=n;i++){
		cin >> a[i];
		maxa = max(a[i],maxa);
		
	}
	
	for(int k =1;k<=n;k++){
		for(int i =k;i<=n;i++){
			if(b[a[i]] == 0){
				b[a[i]]++;
				frist[a[i]] = i;
			}
			else{
				for(int j =frist[a[i]];j<i;j++){
					long long p= b[a[j]]-1;
					long long o = 0;
					b[a[j]] = max(p,o);
			
					
				}
				b[a[i]]++;
			}
			
			
		}
		for(int i =1;i<=maxa;i++){
			ans[i] += b[i];
		}
		for(int i =1;i<=maxa;i++){
			b[i] = 0;
		}
		 
	}
	for(int i =1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;

}
