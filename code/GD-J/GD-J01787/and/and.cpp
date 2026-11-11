#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 200005;
const int LOGN = 29;

int read(){
	int k = 0;char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())k=(k<<1)+(k<<3)+(c^48);
	return k; 
}

int n,m; 

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	vector<int>a(n,0);
	for(int i = 0;i<n;i++){
		a[i] = read();
	}
	int ans = 0;
	for(int i = LOGN;i>=0;i--){
		vector<int>temp;
		for(int j = 0;j<a.size();j++){
			if(a[j]>>i&1)temp.push_back(a[j]);
		}
		if(temp.size()>=m){
			a=temp;
			ans += (1<<i);
		}
	}
	cout<<ans; 
} 
