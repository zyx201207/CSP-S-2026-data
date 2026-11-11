#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	
	sort(a,a+n);
	long long last_id=0,cnt_crystal=1,sum_magic=0;
	for (int i=1;i<n;i++){
		sum_magic+=(long long)( (a[i]-a[i-1])*cnt_crystal );
		cnt_crystal++;
		while(sum_magic>m){
			sum_magic-=a[i]-a[last_id];
			cnt_crystal--;
			last_id++;
		}
		ans=max(ans,cnt_crystal);
	}
	
	
	cout<<ans;
	
	
	return 0;
}