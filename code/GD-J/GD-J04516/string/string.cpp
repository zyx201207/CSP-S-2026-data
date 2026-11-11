#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans=0;
string c[30];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	
	if(n<=2){
		cout<<0;
		return 0;
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			ans++;
			l++;
			r--;
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
