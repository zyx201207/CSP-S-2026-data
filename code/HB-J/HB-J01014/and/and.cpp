#include<bits/stdc++.h>
using namespace std;
long long n,m,max_s1=0;
int a[200005];
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
		if(a[i]>max_s1){
			max_s1=a[i];
			}
		}
		cout<<max_s1;
	return 0;
}

