#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	long long ans=0;
	cin>>n;
	
	deque <long long> a;
	deque <char> c;
	
	long long ai;
	char ci;
	long long maxn=-1024;
	for(int i=0;i<n;i++){
		
		cin>>ai>>ci;
		a.push_back(ai);
		c.push_back(ci);
		maxn=max( ai , maxn );
		
	}
	
	if( n <= 2000 && maxn <= 500 ){
		
		string s="";
		
		for(int i=0;i<n;i++){
			
			for(int j=0;j<a[i];j++){
				
				s+=c[i];
				
			}
			
		}
		
		for(int l=0,r=s.size()-1;l<r;l++,r--){
			
			if( s[l] != s[r] ){
				
				ans++;
				
			}
			
		}
		
		cout<<ans;
		
		return 0;
		
	}
	
	long long minn;
	while(n>1){
		
		minn=min( a.front() , a.back() );
		
		a[0]-=minn;
		a[n]-=minn;
		
		if( c.front() != c.back() ){
			
			ans+=minn;
			
		}
		
		if( a.front() == 0 ){
			
			a.pop_front();
			c.pop_front();
			n--;
			
		}
		if( a.back() == 0 ){
			
			a.pop_back();
			c.pop_back();
			n--;
			
		}
		
	}
	
	cout<<ans;
	
	return 0;
}