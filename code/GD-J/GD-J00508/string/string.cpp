#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
long long ans = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	int i = 1,j = n;
	while(i < j){
		if(c[i] == c[j]){
			if(a[i] == a[j]){
				a[i] = 0;
				a[j] = 0;
				i++;
				j--;	
			}
			else if(a[i] < a[j]){
				a[j] -= a[i];
				a[i] = 0;
				i++;
			}
			else{
				a[i] -= a[j];
				a[j] = 0;
				j--;
			}
		}
		else if(c[i] != c[j]){
			if(a[i] == a[j]){
				ans+=a[i]; 
				a[i] = 0;
				a[j] = 0;
				i++;
				j--;	
			}
			else if(a[i] < a[j]){
				a[j] -= a[i];
				ans+=a[i];
				a[i] = 0;
				i++;
			}
			else{
				ans+=a[j];
				a[i] -= a[j];
				a[j] = 0;
				j--;
			}
		}
	}
	cout << ans;
	return 0;
} 
