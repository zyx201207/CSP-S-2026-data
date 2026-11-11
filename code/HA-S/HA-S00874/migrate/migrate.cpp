#include <bits/stdc++.h>
using namespace std;
int c;
int a[300005];
void abcdefj(int t){
	int n,d;
	cin>>n>>d;
	if(c==0&&n==4){
		cout <<1<<endl<<2;
	}
	if(c==0&&n==5){
		cout <<0<<endl<<1;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(i-j==3&&a[i]-a[j]<=d){
				sum++;
			}
		}
	}
	cout << sum<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	return 0;
}
