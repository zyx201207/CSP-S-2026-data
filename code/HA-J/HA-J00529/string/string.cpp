#include<bits/stdc++.h>
using namespace std;
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,ans=0;cin>>n;
	for(int i=0;i<n;i++){
		int a;
		string b;
		cin>>a>>b;
		for(int j=0;j<a;j++){
			c+=b;
			cnt++;
		}
	}
	int e=0;
	for(int i=0;i<cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			if(c[i]==c[j]){
				e=1;
			}else{
				e=0;
			}
		}
	}
	if(e==1){
		cout<<0;
		return 0;
	}else{
		int i=0,j=cnt-1;
		while(i!=j){
			if(cnt/2==i||cnt/2==j){
				break;
			}
			if(c[i]!=c[j]){
				c[j]=c[i];
				ans++;
			}
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
