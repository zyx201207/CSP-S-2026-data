#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,s,v,ans;

int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;){
		s=0,v=0;
		for(int k=i-1;k>0;k--){
			v++;
			s+=a[i]-a[k];
			if(s>m){
				v--;
				break;
			}
		}
		ans=max(v,ans);
		i++;
		while(a[i]==a[i+1] || i<=n){
			i++;
		}
		
	}
	
	
	cout << ans+1;
	fclose(stdin);fclose(stdout);
	return 0;
	
} 
