#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=m;
	int i=1;
	while(m){
		if(i>n)break;
		if(a[i]!=a[i+1]){
			for(int j=1;j<=i;j++){
				m--;
				a[j]++;
			}
		}else{
			i++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
    return 0;
}
