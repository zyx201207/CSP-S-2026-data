#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<char> b;
void pts4(){
	cout<<0;
}
void pts0(){
	cin>>n;int sum=0;
	a.push_back(0);
	b.push_back('?');
	for(int i=1;i<=n;i++){
		int x;char y;cin>>x>>y;
		a.push_back(x);
		b.push_back(y);
		sum+=a[i];
	}
	int len=sum/2;sum=0;
	int l=1,ans=0;
	while(sum<=len){
		if(sum+a[l]>len){
			a[l]=len-sum;
		}
		while(a[l]>0){
			if(a[a.size()-1]>a[l]){
				a[a.size()-1]-=a[l];a[l]=0;
				if(b[l]!=b[b.size()-1]) ans+=a[l];
			}else{
				a[l]-=a[a.size()-1];
				if(b[l]!=b[b.size()-1]) ans+=a[a.size()-1];
				a.pop_back();
				b.pop_back();
			}
		}
		l++;
	}
	cout<<ans;
}
void pts56(){
	cin>>n;
	string s;
	int ans=0;
	for(int i=1;i<=n;i++){
		int a;string b;cin>>a>>b;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	pts56();
	return 0;
}

