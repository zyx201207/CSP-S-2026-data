#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[300005],cnt2[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x,ans,sum=0;
	bool f=1;
	string s="";
	cin >> n >> m;
	cin >> a[1];
	ans=a[1];
	cnt2[ans]++; 
	for(int i=2;i<=n;i++){
		cin >> a[i];
		if(a[i]<ans){
			f=0;
		}else{
			ans=a[i];
			cnt2[ans]++;
		}
	}
	if(f){
		for(int i=1;i<=m;i++){
			if(i>=a[1] && i<=ans){
				cout << sum+cnt2[i] << " ";
				sum+=cnt2[i];
			}else{
				cout << 0 << " ";
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		s="";	
		for(int j=i;j<=n;j++){
			x=s.find(a[j]+'0');	
			if(x>=0 && x<s.size()){
				s.erase(x,s.size()-x); 
			}
			s+=a[j]+'0';
		}
		for(int j=0;j<s.size();j++){
			cnt[s[j]-'0']++;
		}	
	}
	for(int i=1;i<=m;i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
