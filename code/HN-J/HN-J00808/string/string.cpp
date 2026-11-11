#include<bits/stdc++.h>
using namespace std;
long long n,m[200005],m1[200005],sum,k;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	k = n;
	for(int i = 1;i <= n;i++){
		cin>>m[i]>>b[i];
		m1[i] = m[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m[i];j++){
			if(b[i] != b[k]){
				sum++;
			}
			m1[k]--;
			if(m1[k] == 0){
				k--;
			}
		}
	}
	cout<<sum/2;
	return 0;
}
