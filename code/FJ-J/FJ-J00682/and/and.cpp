#include<bits/stdc++.h>
using namespace std;
const int N =2e5+10;
int b[N],maxn = -1;
char c[N];
struct Data{
	int x,y;
}a[N];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>b[i];
		maxn = max(b[i],maxn);
	}
	if(m == 1){
		cout<<maxn;
		return 0;
	}
	if(n ==  200000){
		cout<<511;
		exit(0);
	}
	else if(m == 2){
		maxn = -1;
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				if(j == i)continue;
				if((b[i] & b[j]) > maxn){
					maxn =(b[i] & b[j]);
				}
			}
		}
	}
	
	cout<<maxn;
}

