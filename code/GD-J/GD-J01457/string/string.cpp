#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[9000000],d;
long long n,c,h= 1,cm,ans,r,l;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i =1;i<=n;i++){
		cin>>c;
		cin>>d;
		for (int j = h;j<=h+c-1;j++){
			a[j] = d;
		}h+=c;
	} if ((h-1)%2 == 0){
		r=1;
		l = h-1;
		while (r<l){
			if (a[r] != a[l]){
				ans++;
			}
			r++;
			l--;
		}
		
	}else{
		r = 1;
		l = h-1;
		while(r+1<=l-1){
			if (a[r] != a[l]){
				ans++;
			}
			r++;
			l--;
		}
	}cout<<ans;
	
	
	return 0;
} 
