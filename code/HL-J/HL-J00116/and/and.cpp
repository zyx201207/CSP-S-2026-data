#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000;
int a[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=INT_MIN;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if((a[i]&a[j])>sum)sum=(a[i]&a[j]);
        }
	}
	cout<<sum;
	return 0;
}
