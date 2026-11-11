#include<bits/stdc++.h>
using namespace std;
string w;
bool b[10];
long long n,cnt,sum; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){	
		long long qq;
		char ww;
		cin>>qq>>ww;
		for(int i=1;i<=qq;i++){
			cout<<1;// 
			cnt++;
			w[cnt]=ww;
		}	
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cnt/2;i++){
		if(w[i]!=w[cnt-i+1])sum++;
	}
	cout<<sum;
	return 0;
} 
