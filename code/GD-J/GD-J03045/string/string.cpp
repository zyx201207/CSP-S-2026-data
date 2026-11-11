#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	string a="";
	for(int i=1;i<=n;i++){
		int num;
		char c;
		cin>>num>>c;
		// while(num--){
		// 	a+=c;
		// }
		a.append(num,c);
	}string b=a;
	//reverse(b.begin(),b.end());
	for(int i=0;i<=a.size()/2;i++){
		if(a[i]!=a[a.size()-i-1]){
			ans++;
		}
	}cout<<ans;
	return 0;
}
