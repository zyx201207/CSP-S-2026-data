#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N],t[N],o[N]; 
string su[N];
string dfs(int x){
	string k;
	while(x){
		int o=x%2;     
		x/=2;
		k+=o+'0';
	}
	return k;
}
int dv(string x){
	int p=x.size()-1;
	int sum=0,z=0;
	for(int i=p;i>=0;i--){
		sum+=pow(z,x[i]-'0');
		z++;
    }
    return z;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		su[i]=dfs(a[i]);
	}
	for(int i=1;i<=n;i++){
		int w=su[i].size();
		for(int j=0;j<w;j++){
			if(su[i][j]=='1'){
				t[j]++;
			}
		}
	}
	int p=-1;
	for(int i=30;i>=0;i--){
		cout<<t[i]<<" ";
	}
	for(int i=30;i>=0;i--){
		if(t[i]>=m){
			p=i;
			break;
		}
	}
	if(p==-1){
		cout<<0;
		return 0;
	}
	cout<<p;
	queue<string>q,qq;
	for(int i=1;i<=n;i++){
		if(su[i][p]=='1'){
			q.push(su[i]);
		}
	}
	for(int i=p-1;i>=0;i--){
		if(q.size()<m){
			break;
		}
		int y=qq.size();
		int k=0,z=q.size();
		for(int i=1;i<=z;i++){
			string e=q.front();
			q.pop();
			q.push(e);
			qq.pop();
			qq.push(e);
			if(e[p]=='1'){
				k++;
			}
		}
		if(k>m){
			int u=q.size();
			for(int i=1;i<=u;i++){
				string e=q.front();
				if(e[p]=='1'){
					q.pop();
					q.push(e);
				}else{
					q.pop();
				}
			}
		}
	}
	int y=qq.size();
	int z=2147483647;
	for(int i=0;i<y;i++){
		z&=dv(qq.front());
		qq.pop();
	}cout<<z;
	return 0;
} 
