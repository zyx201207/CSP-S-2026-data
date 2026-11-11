#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s=" ",sons1,sons2;
int n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;//n后面应该用不到 
	while(n--){
		int x;string y;
		cin>>x>>y;
		while(x--){
			s+=y;//拼贴 
		}
	}
	string ts=s;
	reverse(ts.begin(),ts.end());
	if(ts==s){
		cout<<0;
		return 0;
	}
	int mid=s.size()/2;
	//cout<<mid<<" ";
	if(s.size()%2!=0){
		sons1 = s.substr(1,mid);
		sons2 = s.substr(mid+1);
	}
	else{
		sons1 = s.substr(1,mid-1);
		sons2 = s.substr(mid+1);
	}
	reverse(sons2.begin(),sons2.end());
	//cout<<sons1<<" "<<sons2;
	//cout<<sons1.size()<<" "<<sons2.size();
	for(int i=0;i<sons1.size();i++){
		if(sons1[i]!=sons2[i]){
			ans++;
		}
	}
	cout<<ans;
	
	
	
	
	return 0;
}
