#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],cnt;
vector<int> v;
long long b[N];
int main(){
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			int f=1;
			for(int k=i;k<j;k++){
				if(a[j]==a[k]){
					f=k;
					break;
				}
			}
			if(f==0){
				for(long k=f;k<=v.size();k++){
					v[k]=0;
				}	
			}
			v.push_back(a[j]);
		}
		for(int j=0;j<=v.size();j++){
			b[v[i]]+=1;
		}
		for(int j=0;j<=v.size();j++){
			v[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}

