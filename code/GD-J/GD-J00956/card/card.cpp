#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001],fir[10001],num[10001];
vector<int> f;
void solve(int x){
	f.clear();
	memset(fir,0x3f3f,sizeof(fir));
	for(int i=x;i<=n;i++){
		if(fir[a[i]]==0x3f3f){
			f.push_back(a[i]);
			fir[a[i]]=f.size()-1;
		}
		else{
			for(int j=fir[a[i]];j<f.size();j++){
				fir[f[j]]=f[j]=0x3f3f;
			}
			f.push_back(a[i]);
			fir[a[i]]=f.size()-1;
		}
	}
	for(int i=0;i<f.size();i++){
		num[f[i]]++;
	}
}
bool check(){
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1])return false;
	}
	return true;
}
void bs(int x){
	for(int i=a[x];i<=n;i++){
		num[i]++;
	}
}
int main(){
	freopen("card.in","r",stdin);/////
	freopen("card.out","w",stdout);///
	memset(fir,0x3f3f3f,sizeof(fir));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(check){
		for(int i=1;i<=n;i++){
			bs(i);
		}
		for(int i=1;i<=m;i++){
			cout<<num[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}
}
 
