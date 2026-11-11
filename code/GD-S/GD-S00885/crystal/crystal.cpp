#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,max_=LLONG_MIN,min_=LLONG_MAX,a[MAXN];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		max_=(a[i]>max_?a[i]:max_);
		min_=(a[i]<min_?a[i]:min_);
	}
	if(max_==min_){
		cout<<n;return 0; 
	} 
	for(int i=max_;i>=min_;i--){
		int line=i,cnt=0,ans=0;
		for(int j=0;j<n;j++){
			if(a[j]<=line){
				cnt++;
				ans+=line-a[j];
			}
		}
		if(ans<=m){
			cout<<cnt<<endl;//<<' '<<ans<<endl;
			break;
		}
	}///cout<<max_<<' '<<min_;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

