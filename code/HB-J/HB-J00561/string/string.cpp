#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n;
long long ans,temp;
int a[N];
char s[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> s[i];
	}
	int l=1,r=n;
	while(l<r){
		if(a[l] == a[r]){
			if(s[l] != s[r]){
				ans += a[l];
			}
			l++;
			r--;
		}else if(a[l]<a[r]){
			temp = a[r]-a[l];
			a[r] = temp;
			if(s[l]!=s[r]){
				ans += a[l];
			}
			l++;
		}else if(a[l]>a[r]){
			temp = a[l]-a[r];
			a[l] = temp;
			if(s[l] != s[r]){
				ans += a[r];
			}
			r--;
		}
	}
	cout << ans;
	fclose(stdin);
    fclose(stdout);
	return 0;
}
