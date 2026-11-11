#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int l[N];
int s[N];
int len(int x){
	int ans=0;
	while(x>0){
		x/=2;
		ans++;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
		l[i]=len(s[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(l[i]>l[j]){
				swap(l[i],l[j]);
				swap(s[i],s[j]);
			}
		}
	}
	int sum=s[0];
	for(int i=0;i<m;i++){
		sum=(sum & s[i]);
	}
	cout<<sum;
	return 0;
}
