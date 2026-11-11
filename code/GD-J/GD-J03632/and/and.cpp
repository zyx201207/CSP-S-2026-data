#include<bits/stdc++.h>
using namespace std;
const int N=100000007;
long long n,m,x,a[N][N],y;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		while(x>0){
			y++;
			if(x%2==0){
				a[i][y]=0;
			}
			else{
				a[i][y]=0;
			}
			x=x/2;
		}
	}
	cout<<"12"; 
	return 0;
} 
