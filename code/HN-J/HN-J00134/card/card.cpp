#include <bits/stdc++.h>
using namespace std;
int n,m,a[50010],b[50010];
bool used[50010];
vector<int> v;
void del(int x){
	for (int i=1;i<=v.size();i++){
		if (v[i]==x){
			for (int j=i;j<=v.size();j++){
				v[j]=0;
			}
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int num=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for (int i=1;i<=n;i++){
		int s=n-i+1,j=i;
		while (s){
			if (used[a[j]])	del(a[j]);
			used[a[j]]=true;
			v.push_back(a[j]);
			j++;
		}
		for (int i=1;i<=v.size();i++){
			b[v[i]]++;num++;
		}
	}
	for (int i=1;i<=num;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
