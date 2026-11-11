#include <bits/stdc++.h>

using namespace std;

int n,i2=1,j2;
char b[200005];
long long ans=0,a[200005],i1,j1;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	a[0]=0;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
		a[i] += a[i-1];
	}
	i1 = 1 , j1 = a[n];
	j2=n;
	while(i1 <= j1){

		int x = min(a[i2]+1 - i1,j1-a[j2-1]);
		if(b[i2] != b[j2]){
			ans+=x;
		}
		j1 -= x;
		i1+=x;
		if(j1 <= a[j2-1]){
			j2--;
		}
		if(i1 > a[i2]){
			i2++;
		}
	}
	cout << ans;
}
