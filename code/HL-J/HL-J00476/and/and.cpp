#include<bits/stdc++.h>
using namespace std;
int n,m,ans = 0;
bool cmp(int a,int b){
	return a>b;
} 

void solve(int i,vector<int> a){
	for(int p = i;p<m+i;p++){
		ans = ans&a[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie();
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    
    cin>>n>>m;
    vector<int> a(n);
    for(int i = 0;i<n;i++){
    	cin>>a[i];
	}
	sort(a.begin(),a.end(),cmp);
	ans = a[0];
	for(int i = 1;i<m;i++){
		ans = ans&a[i];
	}
	int j = 1;
	while(ans == 0){
		ans = a[j];
		solve(j+1,a);
		j++;
	}
	cout<<ans;
    return 0;
}
