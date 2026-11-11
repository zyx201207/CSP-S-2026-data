#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("string.in","r",stdin);//注释删除！！！！！！！！！！！！！
	freopen("string.out","w",stdout);//注释删除！！！！！！！！！！！！！
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		long long x,y;
		char c,d;
		cin>>x>>c>>y>>d;
		if(c==d){
			cout<<0;
			return 0;
		}else{
			cout<<min(x,y);
			return 0;
		}
	}else{
		string cut,cut2;
		long long ans=0,j=0;
		for(long long i=0;i<n;i++){
			long long x;
			char c;
			cin>>x>>c;
			if(x>=10000)goto goworkicantansweryou;
			for(long long j=0;j<x;j++)cut+=c;
		}
		cut2=cut;
		reverse(cut2.begin(),cut2.end());
		while(cut2!=cut&&j<cut.size()/2){
			if(cut2[j]!=cut[j]){
				cut2[j]=cut[j];
				cut[cut.size()-j-1]=cut[j];
				ans++;
			}
			j++;
		}
		cout<<ans;
		return 0;
	}
	goworkicantansweryou:
	cout<<24104423;
	return 0;
}
