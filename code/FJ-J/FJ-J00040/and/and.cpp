#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=222222;
int a[N];
int cmp(int a,int b){
	return a>b;
}                                                                                                                                                                                       
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}                             
	sort(a+1,a+n+1,cmp);
	set<int>s;
	int p=0;
	for(int i=1;i<=n;i++){
		int k=s.size();
		s.insert(a[i]);
		if(s.size()==m){
			cout<<a[i];                      
			return 0;                                    
		}                                  
	}                                           
	return 0;
}

