#include<bits/stdc++.h>
using namespace std;
struct node{
	int s;
	char k;
} nd[1000100];
void solve(){
	int n;
	long long sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>nd[i].s>>nd[i].k;
	}
	int l=0,r=n-1;
	while(l<r){
		if(nd[l].k==nd[r].k){
			if(nd[l].s>nd[r].s){
				nd[l].s -= nd[r].s;
				r--;
			}else if(nd[l].s<nd[r].s){
				nd[r].s -= nd[l].s;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(nd[l].s>nd[r].s){
				nd[l].s -= nd[r].s;
				sum+=nd[r].s;
				r--;
			}else if(nd[l].s<nd[r].s){
				nd[r].s -= nd[l].s;
				sum+=nd[l].s;
				l++;
			}else{
				sum+=nd[l].s;
				l++;
				r--;
			}
		}
	}
	cout<<sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
} 
