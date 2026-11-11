#include<iostream>
#include<string>
using namespace std;



int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	long long  n,sum=0,ans=0;
	cin>>n;
	long long a[100005]={0};
	string a1[100005],s="";
	for(long long i=0;i<n;i++){
		cin>>a[i]>>a1[i];
		sum+=a[i];
		while(a[i]!=0){
			s+=a1[i];
			a[i]--;
		}
	}
	for(long long i=0;i < sum/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
	}cout<<ans;
	return 0;
}
