#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	vector<long long> a(n+1,0);
	vector<char> c(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	vector<pair<char,long long> > v;
	long long Ans=0;
	char ch;
	for(int i=1;i<=n;i++){
		if(i==1||ch==c[i]){
			ch=c[i];
			Ans+=a[i];
		}
		else{
			v.push_back({ch,Ans});
			ch=c[i];
			Ans=a[i];
		}
	}
	v.push_back({ch,Ans});
	int l=0,r=v.size();
	r--;
	long long Count=0;
	while(l<=r){
		if(v[l].first==v[r].first){
			if(v[l].second==v[r].second)
				l++,r--;
			else if(v[l].second>v[r].second){
				v[l].second-=v[r].second;
				r--;
			}
			else{
				v[r].second-=v[l].second;
				l++;
			}
		}
		else{
			if(v[l].second==v[r].second){
				Count+=v[l].second;
				l++,r--;
			}
			else if(v[l].second>v[r].second){
				v[l].second-=v[r].second;
				Count+=v[r].second;
				r--;
			}
			else{
				v[r].second-=v[l].second;
				Count+=v[l].second;
				l++;
			}
		}
	}
	cout<<Count;

	return 0;
}
