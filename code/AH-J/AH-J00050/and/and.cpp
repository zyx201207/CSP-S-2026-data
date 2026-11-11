#include <bits/stdc++.h>
using namespace std;
string tobin(int x){
	string bin={};
	while(x){
		bin=char((x%2==1)+'0')+bin;
		x/=2;
	}
	return bin;
}
int todex(string x){
	int dex=0;
	for(int i=x.size()-1,p=0;i>=0;i--,p++){
		if(x[i]=='1')
			dex+=pow(2,p);
	}
	return dex;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,ans=0;
	cin >> n >> m;
	if(m==1){
		while(n--){
			int t;
			cin >> t;
			ans=max(ans,t);
		}
		cout << ans;
		return 0;
	}else if(m==n){
		int t;
		cin >> t;
		ans=t;
		n--;
		while(n--){
			cin >> t;
			ans&=t;
		}
		cout << ans;
		return 0;
	}
	vector<int> arr(n);
	vector<string> str(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		str[i]=tobin(arr[i]);
	}
	sort(str.begin(),str.end(),[](string x,string y){
		if(x.size()!=y.size()){
			return x.size()>y.size();
		}else{
			return x>y;
		}
	});
	ans=todex(str[0]);
	for(int i=1;i<m;i++){
		ans&=todex(str[i]);
	}
	cout << ans;
	return 0;
}
/*
1010101000101111
    100101010000
      1110100110
       111000101
        11110011
          100111
           10111
           10111
           10111
             101
it'ssodifficult!
*/
