#include<bits/stdc++.h>
using namespace std;
struct zf{
	long long s;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	zf k[n];
	
	for(int i=0;i<n;i++){
		cin>>k[i].s>>k[i].c;
	}
	long long ans=0;
	int l=0;
	int r=n-1;
	while(r>=l){
		if(k[l].c != k[r].c){
			ans+=min(k[l].s,k[r].s);
		}
		if(k[l].s < k[r].s){
				k[r].s-=k[l].s;
				l++;
			}
			else if(k[l].s == k[r].s){
				l++;
				r--;
			}
			else{
				k[l].s-=k[r].s;
				r--;
			}
	}
	cout<<ans;
	
	return 0;
}
