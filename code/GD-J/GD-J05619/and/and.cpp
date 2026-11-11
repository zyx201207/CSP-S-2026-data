#include<bits/stdc++.h>
using namespace std;
int n,m;
rjz a[100000];
struct rjz{
	int shu;
	int rjz[10086]={0};
};

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].shu;
		long long wei=n/2+1;
		int shang=a[i].shu;
		for(long long j=wei;j>0;j--){
			int yu=shang%2;
			a[i].rjz[j]=yu;
			shang/=2;
		}
		
	}
	for(int ) 
	
	return 0;
}
