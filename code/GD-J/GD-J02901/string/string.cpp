#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
int a[N];
char c[N];
long long sum=0;
void S_small(){
	vector<char> s;
	s.push_back('.');
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s.push_back(c[i]);
		}
	}
	//for(int i=1;i<=sum;i++)cout<<s[i];
	long long l=1,r=sum;
	long long ans=0;
	while(l<r){
		if(s[l]!=s[r])ans++;
		l++;
		r--;
	}
	cout<<ans<<endl;
	return;
}
void S(){
	cin>>n;
	char d;
	bool ck=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		d=c[1];
		if(c[i]!=d){
			ck=0;
			//break;
		}
		//cout<<c[i]<<endl;
		sum+=a[i];
	}
	if(ck){
		cout<<"0"<<endl;
		return;
	} 
	if(sum<=1000000||1){
		S_small();
		return;
	}
	long long ans=0;
	int l=1,r=n;
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) S();
	return 0;
}

