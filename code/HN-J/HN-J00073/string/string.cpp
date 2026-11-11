#include<bits/stdc++.h>
#define int long long;
using namespace std;
const int N=1e7+10;
int a[200005];
char c[200005];
vold solve1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){|
			s+c[i];
		}
	}
	
	int cnt=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
}
vold solve2(){
	int sum=R[n];
	for(int i=1;i<=n;i++){
		if(L[i]>sum/2) continue;
		if(R[i]>sum/2) continue;
		int it1=upper_bound(L+1,L+N+1,sum-R[i]+1)-L;
		int it2=upper_bound(R+1,R+N+1,sum-L[i]+1)-R;
		it1--;
		if(it1==it2){
			ans+=(sum-L[i]+1)-(sum-R[i]+1)+1;
		}
		else{
			for(int j=i;j<=it2-1;j++){
				if(c[j]!=c[i]) ans+=R[i]-L[i]+1;
			}
			if(c[it1]!=c[i]){
				ans+=R[it1]-(sum-R[i]+i)+1;			
			}
			if(c[it2]!=c[i]){
				ans+=(sum-L[i]+1)-L[i]+1;
			}
		}
	}
	cout<<ans;
}
signed(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);

}
	
	
	
	
	
	
	
	
	

