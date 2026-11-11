#include<iostream>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s=" ";
    for(int i=1;i<=n;i++){
    	int x;
    	cin>>x;
    	char a;
    	cin>>a;
    	string tmp;
    	for(int j=1;j<=x;j++){
    		tmp+=a;
    	}
    	s+=tmp;
	}
	int l=1,r=s.size()-1;
	int sum=0;
	while(l<r){
		if(s[l]!=s[r]) sum++;
		l++,r--;
	}
	cout<<sum;
	return 0;
} 
