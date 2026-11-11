#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	long long n;
	string s;
	vector<long long> a(n);
	vector<char> c(n);
	cin>>n;
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		ans+=a[i];
		int x=0;
		while(a[i]--){
			s[x]=c[i];
			x+=1;
		}
	}
	ans/=2;
	long long i=0,j=s.size();
	long long cnt1=0,cnt2=0;
	while(i<ans){
		while(j>=ans){
			i++,j--;
			if(!(s[i]-'0'==s[j]-'0')){
				cnt1+=1;
			}
		}
	}
	i=s.size(),j=0;
	while(i>=ans){
		while(j<ans){
			i--,j++;
			if(!(s[i]-'0'==s[j]-'0')){
				cnt2+=1;
			}
		}
	}
	cout<<min(cnt1,cnt2);
	return 0;
}
