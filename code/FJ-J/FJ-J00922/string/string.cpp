#include<bits/stdc++.h>
using namespace std;

struct s{
	long long x;
	char c;
	
};

int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	
	cin >> n;
	vector<s> a;
	char c;
	long long x;
	
	cin >> x >> c;
	a.push_back({x,c});
	for(int i=1;i<n;i++){
		cin >> x >> c;
		if(c==a[a.size()-1].c) a[a.size()-1].x+=x;
		else a.push_back({x,c});
		
	}
	
	long long l=0,r=a.size()-1,ans=0;
	
	while(l<r){
		if(a[l].x<a[r].x) ans+=a[l].x,a[r].x-=a[l].x,l++;
		else if(a[l].x>a[r].x) ans+=a[r].x,a[l].x-=a[r].x,r--;
		else ans+=a[l].x,l++,r--;
		
	}
	
	cout << ans;
	
	return 0;
}
