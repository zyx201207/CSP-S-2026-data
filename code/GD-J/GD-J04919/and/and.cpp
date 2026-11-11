#include<bits/stdc++.h>
using namespace std;
int n,m,w;
long long ans;
string a[200005],s[200005],sans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		int x;cin>>x;
		string d;
		while(x){
			a[i] += char((x&1)+'0');
			x = x>>1;
		}for(int j = a[i].size()-1;j>=0;j--) d += a[i][j];
		swap(a[i],d);
		int k = a[i].size();
		w = max(w,k);
	}for(int i = 1;i<=n;i++){
		if(a[i].size()<w) while(a[i].size()<w) a[i] = "0"+a[i];
	}for(int i = 0;i<w;i++){
		int f = 0;
		for(int j = 1;j<=n;j++){
			if(a[j][i]=='1') s[++f] = a[j];
		}if(f>=m){
			sans += '1';
			swap(a,s);
			n = f;
		}else{
			sans += '0';
		}
	}for(int i = 0;i<sans.size();i++){
		if(sans[i]=='0') continue;
		int f = 1;
		for(int j = 1;j<=sans.size()-i-1;j++) f *= 2;
		ans += f;
	}cout<<ans;
	return 0;
}
