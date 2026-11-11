#include<bits/stdc++.h>
using namespace std;
long long n,m,fi,s;
long long nl[100005];
int ans = 1,bj = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	fi = m;
	for(int i = 1;i<=n;i++){
		cin>>nl[i];
	}
	sort(nl,nl+n+1);
	for(int i=n;i>0;i--){
		for(int k = i-1;k>0;k--){
			s = nl[k];
			s += fi;
			if(s>nl[i]){
				fi = s - nl[i];
				bj++;
				continue;
			}
			if(s == nl[i]){
				bj++;
				break;
			}
		}
		for(int k = i+1;k<=n;k++){
			if(nl[k] == nl[i])bj++;
			if(nl[k] != nl[i])break;
		}
		if(bj > ans){
			ans = bj;
		}
		fi = m;
		bj = 1;
	}
	cout<<ans;
}
