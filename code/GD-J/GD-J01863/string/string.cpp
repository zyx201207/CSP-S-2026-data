#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n;
int a[N];
string s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> s[i];
	}
	long long ans = 0;
	int i = 1,j = n;
	while(i<j){
		if(a[i]>=a[j]){
			a[i] = a[i]-a[j];
			if(s[i]!=s[j])ans+=1LL*a[j];
			j--;
		}else{
			a[j] = a[j]-a[i];
			if(s[i]!=s[j])ans+=1LL*a[i];
			i++;
		}
		
	}
	cout << ans << "\n";
	return 0;
}



