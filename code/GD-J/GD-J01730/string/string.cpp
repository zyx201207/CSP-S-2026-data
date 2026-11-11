#include<bits/stdc++.h>
using namespace std;
int n,cnt,sum,ans;
string a,b;
bool judge(string x,string y){
	for(int i=1;i<=cnt;i++){
		if(x[i]!=y[i]) return false;
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		char y;
		cin>>y;
		for(int i=1;i<=x;i++){
			a[cnt+i]=y;
		}
		cnt+=x;
	}
	for(int i=cnt;i>=1;i--){
		b[++sum]=a[i];
	}
	
	if(judge(a,b)){
		cout<<0;
		return 0;
	}else{
		if(cnt%2==0){
			int k=cnt/2;
			for(int i=1;i<=k;i++){
				if(a[i]!=b[i]) ans++;
			}
		}else{
			int k=cnt/2;
			for(int i=1;i<=k;i++){
				if(a[i]!=b[i]) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
