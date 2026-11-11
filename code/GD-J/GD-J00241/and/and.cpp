#include<bits/stdc++.h>
using namespace std;
int nums[200005];
bool debug = 0;
bool cmp(int a,int b){
	return a>b;
}
string toBin(int n){
	string out = "";
	while(n){
		out += ((n % 2)+'0');
		n /= 2;
	}
	reverse(out.begin(),out.end());
	if(debug) cout << "toBin:" << out << endl;
	return out;
} 
int toTen(string s){
	int out = 0;
	for(int i = 0;i<s.size();i++){
		out += (s[i]-'0')*((int)pow(2,s.size()-1-i));
	}
	if(debug) cout << "toTen:" << out << endl;
	return out;
}
int awy(int a,int b){
	string abinn = toBin(a);
	string bbinn = toBin(b);
	string outbin = "";
	reverse(abinn.begin(),abinn.end());
	reverse(bbinn.begin(),bbinn.end());
	for(int i = 0;i<max(abinn.size(),bbinn.size());i++){
		if(i>=min(abinn.size(),bbinn.size())){
			outbin += "0";
			continue;
		}
		if(abinn[i]==bbinn[i]){
			outbin += "1";
		}else{
			outbin += "0";
		}
	}
	reverse(outbin.begin(),outbin.end());
	int toT = toTen(outbin);
	if(debug) cout << "[awy] outbin:" << outbin << " tnum:" << toT << endl;
	return toT;
}
int main(){
	if(!debug){
		freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
	}
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> nums[i];
	}
	sort(nums+1,nums+1+n,cmp);
	int ans = nums[1];
	for(int i = 2;i<=m;i++){
		ans = awy(ans,nums[i]);
	}
	cout << ans;
}
