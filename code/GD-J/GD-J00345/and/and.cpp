#include<iostream>
using namespace std;
int  a[200005];
bool b[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=1;
	}int sum=0;
	for(int j=30;j>=0;j--){
		int p=0;
		for(int i=1;i<=n;i++){
			if(b[i] and ((a[i]>>j)&1)){
				p++;
			}
		}if(p>=m){
			sum+=(1<<j);
			for(int i=1;i<=n;i++){
				if(b[i] and (!((a[i]>>j)&1))){
					b[i]=0;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
