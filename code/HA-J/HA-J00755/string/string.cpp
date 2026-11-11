#include<bits/stdc++.h>
using namespace std;
int n,h=0,ans=0;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int w;
		cin>>w;
		h+=w;
		string b;
		cin>>b;
		for(int i=1;i<=w;i++){
			a+=b;
		}
	}
	int i=0;
	int j=n;
	while(i!=(h+1)/2-1&&j!=(h+1)/2-1){
		if(a[i]!=a[j]){
			a[j]=a[i];
			ans++;
		}
		i++;
		j--;
		
	}
	cout<<ans;
	return 0;
} 
