#include<bits/stdc++.h>
using namespace std;
int ma=0;
int n,m;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	set<int> pc;
	cin >> n >> m;
	vector<int> a(n);
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	if (a[a.size()-1]%2==0&&a[a.size()-2]%2==0){
		cout << 0;
	}else{
		int no=a[a.size()-1];
		for(int i=1;i<m;i++){
			no&=a[a.size()-1-i];
		}
		cout << no;
	}
	
	return 0;
} 

