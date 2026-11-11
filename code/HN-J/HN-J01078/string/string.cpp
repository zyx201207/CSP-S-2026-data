#include <bits/stdc++.h>
using namespace std;
long long n,a[20007];
char c[20007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
	}
	long long left_index=0,right_index=n-1,ans=0;
	while(left_index<right_index){
		if(a[left_index]==0) left_index++;
		if(a[right_index]==0) right_index--;
		if(c[left_index]!=c[right_index]) ans+=min(a[left_index],a[right_index]);
		a[left_index]-=min(a[left_index],a[right_index]);
		a[right_index]-=min(a[left_index],a[right_index]);
	}
	cout << ans;
	return 0;
}
