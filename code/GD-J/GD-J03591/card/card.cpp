#include<bits/stdc++.h>
using namespace std;

int n,m,a[500010];
long long num[300010];
bool b[300010];
void Main(int x){
	memset(b,false,sizeof(b));
	vector<int> v;
	for(int i = x;i <= n;i++){
		if(b[a[i]]){
			while(v.back() != a[i]){
				b[v.back()] = false;
				v.pop_back();
			}
			v.pop_back();
		}
		v.push_back(a[i]);
		b[a[i]] = true;
	}
	while(v.size()){
		num[v.back()]++;
		v.pop_back();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int i = 1;i <= n;i++)Main(i);
	for(int i = 1;i <= m;i++)cout<<num[i]<<' ';
	return 0;
}  

