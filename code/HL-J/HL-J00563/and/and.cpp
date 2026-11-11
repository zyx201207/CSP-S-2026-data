#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	long long s[n+1]={};
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(s[i]<s[j]){
				swap(s[i],s[j]);
			}
		}
	}
	int h=s[0];
	int z=0;
	while(m){
		h=h&s[z];
		m--;
		z++;
	}
	cout<<h;
	return 0;
}