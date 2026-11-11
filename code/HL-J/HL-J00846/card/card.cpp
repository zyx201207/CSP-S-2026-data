//邦吧卡邦~
//爱丽丝要成为最厉害的OIer！
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,m;
int a[N];
int ans[N];
int mfind(vector<int> v1,int x){
	for(int i=0;i<v1.size();i++){
		if(v1[i]==x) return i;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> v;
		for(int j=i;j<=n;j++){
			int t=mfind(v,a[j]);
//			cout<<"mfind("<<a[j]<<"):" <<mfind(v,a[j])<<endl;
//			for(auto c:v){
//				cout<<c<<" ";
//			}
//			cout<<endl;
			if(t==-1){
				v.push_back(a[j]);
			}
			else{
				while(v[v.size()-1]!=a[j]){
					v.pop_back();
				}
			}
		}
//		cout<<"arr:";
//		for(auto c:v){
//			cout<<c<<" ";
//		}
//		cout<<endl<<endl;
		for(int j=1;j<=m;j++){
			if(mfind(v,j)!=-1) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
