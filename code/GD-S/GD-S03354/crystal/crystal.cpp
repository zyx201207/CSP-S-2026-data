#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000005],sum; 
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	while(m>0){
		for(int i=1;i<=n;i++){
			if(a[i]+1<=a[n/2]){
				a[i]+=1;
				m--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			sum++;
		}
	}
	cout << sum;
	
    fclose(stdin);
	fclose(stdout);
	return 0;
} 
