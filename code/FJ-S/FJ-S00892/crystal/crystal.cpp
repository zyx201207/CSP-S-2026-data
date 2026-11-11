#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=-1;
	cin>>n>>m;
	vector<long long> crys,prefix;
	crys.resize(n);
	prefix.resize(n+1);
	bool isPointA=true,isPointB=true;
	for(int i=0;i<n;i++) {
		cin>>crys[i];
		if(i!=0 && crys[i-1]!=crys[i]) isPointA=false;
		if(i>1 && crys[i]-crys[i-1]!=crys[i-1]-crys[i-2]) isPointB=false;
	}
	if(isPointA){
		cout<<n;
		return 0;
	}
	if(isPointB){
		long long cnt=0,step=m/(int)abs(crys[1]-crys[0]),ans=1; 
		while(cnt<step){
			cnt+=ans;
			ans++;
		} 
		cout<<ans;
		return 0;
	}
	sort(crys.begin(),crys.end(),cmp);
	for(int i=0;i<n;i++) prefix[i+1]=prefix[i]+crys[i];
	for(int a=0;a<n;a++){
		for(int b=a;b<n;b++){
			if((b-a+1)*crys[b]-prefix[b+1]+prefix[a]<=m) {
				ans=max(ans,(long long)b-a+1);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
