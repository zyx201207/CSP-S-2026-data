#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
	int n=0,f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int main(){
	//freopen("D://down/card/card2.in","r",stdin);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n=read(),m=read();
	vector<int> arr(n);
	vector<vector<int>> ans;
	for(int i=0;i<n;i++)arr[i]=read();
	for(int j=0;j<n;j++){
		vector<int> v;
		for(int i=j;i<n;i++){
			int x=arr[i];
			bool check=true;
			for(auto k:v){
				if(k==x){
					check=false;
					break;
				}
			}
			if(check)v.push_back(x);
			else{
				while(v.back()!=x)v.pop_back();
				v.pop_back();
				v.push_back(x);
			}
		}
		ans.push_back(v);
	}
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(auto j:ans){
			for(auto k:j){
				if(k==i){
					cnt++;
					break;
				}
			}
		}
		cout<<cnt<<" ";
	}
	return 0;
}
//jian nan ru dong 
//o bu bu bu T2 mei zuo chu lai wo wu yi shi fen nu de
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
//sto xi xi ai fo orz
