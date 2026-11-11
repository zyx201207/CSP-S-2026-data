#include<bits/stdc++.h>
using namespace std;
namespace FZT{
typedef long long ll;
const int N=2e5+5;
int n,m,a[N],ans;
vector<int>v[35];
vector<int>tmp;
void Main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[31].push_back(a[i]);
	}
	for(int j=30;j>=0;j--){
		int sum=0;
		for(auto x:v[j+1]){
			if(x&(1<<j)){
				sum++;
				tmp.push_back(x);
			}
		}
		if(sum>=m){
			v[j]=tmp;
			ans+=(1<<j);
		}
		else v[j]=v[j+1];
		tmp.clear();
	}
	cout<<ans;
}}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	FZT::Main();
	return 0;
}
